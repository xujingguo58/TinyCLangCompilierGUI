vector<int>basic_block;//基本块地址

int setstart(int i){//求基本块地址  
	if (temp_code[i].op == "if") return 1;
	else if (temp_code[i].op == "el") return 0;
	else if (temp_code[i].op == "ie") return 0;
	else if (temp_code[i].op == "wh") return 1;
	else if (temp_code[i].op == "do") return 0;
	else if (temp_code[i].op == "we") return 0;
	else return -1;
}
void divide_block()  {//划分基本块
	int i;
	basic_block.push_back(0);
	int basic_block_size = temp_code.size();//四元式容量
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
template <class Type>   //模板，字符串转常数
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}
string NumToString(float num){  //申请临时变量
	stringstream ss;  //将t转换为字符串 
	ss << num;
	//ss.str();
	string s;
	s = ss.str();
	return s;
}
void opt_constant(){//优化常数
	divide_block();     //划分基本块
	int delCount = 0;
	int i = 0;
	int basic_block_size = basic_block.size();//基本块容量
	int last_i = 0;
	int now_i = 0;
	while (i < basic_block_size){
		last_i = now_i;
		now_i = basic_block[i];
		for (int j = last_i; j <= now_i; j++)//基本块
			if (isNum(temp_code[j].arg1) == 1 && isNum(temp_code[j].arg2) == 1){//常数计算
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
void opt_common(){//优化公因子
	divide_block();     //划分基本块
	int i = 0;
	int basic_block_size = basic_block.size();//基本块容量
	int last_i = 0;
	int now_i = 0;
	while (i < basic_block_size){
		last_i = now_i;
		now_i = basic_block[i];
		for (int j = last_i; j <= now_i; j++){//基本块 
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