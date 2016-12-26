vector<int>basic_block;//�������ַ

int setstart(int i){//��������ַ  
	if (temp_code[i].op == "if") return 1;
	else if (temp_code[i].op == "el") return 0;
	else if (temp_code[i].op == "ie") return 0;
	else if (temp_code[i].op == "wh") return 1;
	else if (temp_code[i].op == "do") return 0;
	else if (temp_code[i].op == "we") return 0;
	else return -1;
}
void divide_block()  {//���ֻ�����
	int i;
	basic_block.push_back(0);
	int basic_block_size = temp_code.size();//��Ԫʽ����
	for (i = 0; i<basic_block_size; i++){
		if (setstart(i) == 0)
			basic_block.push_back(i);
		else if (setstart(i) == 1){
			i++;
			basic_block.push_back(i);
		}
	}

}

float toNum(string str){
	float result = 0;
	int i;
	for (i = 0; i < str.size(); i++){
		if (str[i] == '.')
			break;
	}
	if (i == str.size()){
		for (int j = 0; j < str.size(); j++){
			result = (str[i] - '0')*pow(10, j);
		}
	}
	return result;
}
template <class Type>   //ģ�壬�ַ���ת����
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}
string NumToString(float num){  //������ʱ����
	stringstream ss;  //��tת��Ϊ�ַ��� 
	ss << num;
	//ss.str();
	string s;
	s = ss.str();
	return s;
}
void opt_constant(){//�Ż�����
	divide_block();     //���ֻ�����
	int delCount = 0;
	int i = 0;
	int basic_block_size = basic_block.size();//����������
	int last_i = 0;
	int now_i = 0;
	while (i < basic_block_size){
		last_i = now_i;
		now_i = basic_block[i];
		for (int j = last_i; j <= now_i; j++)//������
			if (isNum(temp_code[j].arg1) == 1 && isNum(temp_code[j].arg2) == 1){//��������
				temp_code[j].op = "=";
				float temp_result = stringToNum<float>(temp_code[j].arg1);
				temp_result += stringToNum<float>(temp_code[j].arg2);
				temp_code[j].arg1 = NumToString(temp_result);
				temp_code[j].arg2 = "_";

				if (temp_code[j].result == temp_code[j + 1].arg1){
					delCount++;
					temp_code[j + 1].arg1 = temp_code[j].arg1;
					int m = j, n = j + 1;
					while (n < temp_code.size()){
						temp_code[m] = temp_code[n];
						m++; n++;
					}
				}
			}
		i++;
	}


	for (int k = 0; k < delCount; k++){
		temp_code.pop_back();
		basic_block.pop_back();
	}
	basic_block.clear();
}
void opt_common(){//�Ż�������
	divide_block();     //���ֻ�����
	int i = 0;
	int basic_block_size = basic_block.size();//����������
	int last_i = 0;
	int now_i = 0;
	while (i < basic_block_size){
		last_i = now_i;
		now_i = basic_block[i];
		for (int j = last_i; j <= now_i; j++){//������ 
			//char t=
			if (temp_code[j].result[0] == 't')
				for (int k = j; k <= now_i; k++){
					if (temp_code[k].result[0] == 't')
						if (temp_code[k].arg1 == temp_code[j].arg1)
							if (temp_code[k].arg2 == temp_code[j].arg2)
								if (temp_code[k].op == temp_code[j].op){
									//cout << "here" << endl;
									temp_code[k].result = temp_code[j].result;
								}
				}
		}
		i++;
	}
}