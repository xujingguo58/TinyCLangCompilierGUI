

vector<string> object_code; //目标代码存储的容器
vector<string> t_vector;
int x;
vector<int> sem;
int checkTStack(string t_result){
	for (auto t : t_vector){
		if (t == t_result)
			return 0;
	}
	return 1;
}
int c = 0;
string getC(int i){//获得code代码段的标号{
	stringstream ss;  //将t转换为字符串 
	ss << i;
	//ss.str();
	string s;
	s = ss.str();
	string result = "flag" + s;
	return result;
}

int returnType(string name){
	for (auto t : identifier_table){
		if (name == t.name){
			return t.type;
		}
	}
	if (isNum(name))
		return 4;
}
int temp_T = t;
int checkTempCode(){
	for (auto t : temp_code){
		if (t.arg1 != "_" || t.arg2 != "_"){
			if (returnType(t.arg1) != returnType(t.arg2)) {  //表达式类型前后不匹配
				//cout << t.arg1 << " " << t.arg2 << endl;
				return 3003;			//表达式类型不匹配
			}
		}
	}
	return 1;
}
string codeX(int i){
	stringstream ss;  //将t转换为字符串 
	ss << i;
	string s;
	s = ss.str();
	string result = "code" + s;
	//c++;
	return result;
}
void translateTempcode(){
	for (int i = 0; i < temp_code.size(); i++){
		tempCode t = temp_code[i];
		if (t.op == "main"){
			object_code.push_back("START:");
		}
		if (t.op == "="){
			//object_code.push_back("MOV     " + t.result + "," + t.arg1);
			object_code.push_back("MOV      DX,"+t.arg1);
			object_code.push_back("MOV      "+t.result+",DX" );
		}
		if (t.op == "+"){			//加法
			object_code.push_back("MOV     AX," + t.arg1);
			object_code.push_back("MOV     BX," + t.arg2);
			object_code.push_back("ADD     AX,BX");
			object_code.push_back("MOV     " + t.result + ",AX");
		}
		if (t.op == "-"){
			object_code.push_back("MOV     AX," + t.arg1);
			object_code.push_back("MOV     BX," + t.arg2);
			object_code.push_back("SUB     AX,BX");
			object_code.push_back("MOV     " + t.result + ",AX");
		}
		if (t.op == "*"){
			object_code.push_back("MOV     AX," + t.arg1);
			object_code.push_back("MOV     BX," + t.arg2);
			object_code.push_back("MUL     AX,BX");
			object_code.push_back("MOV     " + t.result + ",AX");
		}
		if (t.op == "/"){
			object_code.push_back("MOV     AX," + t.arg1);
			object_code.push_back("MOV     BX," + t.arg2);
			object_code.push_back("DIV     AX,BX");
			object_code.push_back("MOV     " + t.result + ",AX");
		}
		if (t.op == "=="){
			object_code.push_back("MOV     CX," + t.arg1);
			object_code.push_back("CMP     CX," + t.arg2);
			object_code.push_back("JNE     " + getC(c));
			object_code.push_back("MOV     " + t.result + ",1");
			object_code.push_back("JMP     " + getC(c + 1));
			object_code.push_back(getC(c) + ":");
			object_code.push_back("MOV     " + t.result + ",0");
			object_code.push_back(getC(c + 1) + ":");
			c++; i++;
			t = temp_code[i];
			if (t.op == "if"){
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNZ     " + codeX(x + 1));
			}
			if (t.op == "wh"){
				object_code.push_back(codeX(x) + ":");
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNE     " + codeX(x + 1));
			}
		}
		if (t.op == "!="){
			object_code.push_back("MOV     CX," + t.arg1);
			object_code.push_back("CMP     CX," + t.arg2);
			object_code.push_back("JNE     " + getC(c));
			object_code.push_back("MOV     " + t.result + ",0");
			object_code.push_back("JMP     " + getC(c + 1));
			object_code.push_back(getC(c) + ":");
			object_code.push_back("MOV     " + t.result + ",1");
			object_code.push_back(getC(c + 1) + ":");
			c++;
		}
		if (t.op == ">"){
			object_code.push_back("MOV     CX," + t.arg1);
			object_code.push_back("CMP     CX," + t.arg2);
			object_code.push_back("JLE     " + getC(c));
			object_code.push_back("MOV     " + t.result + ",1");
			object_code.push_back("JMP     " + getC(c + 1));
			object_code.push_back(getC(c) + ":");
			object_code.push_back("MOV     " + t.result + ",0");
			object_code.push_back(getC(c + 1) + ":");
			c++; i++;
			t = temp_code[i];
			if (t.op == "if"){
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNZ     " + codeX(x + 1));
			}
			if (t.op == "wh"){
				object_code.push_back(codeX(x) + ":");
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNE     " + codeX(x + 1));
			}
		}
		if (t.op == "<"){
			object_code.push_back("MOV     CX," + t.arg1);
			object_code.push_back("CMP     CX," + t.arg2);
			object_code.push_back("JNL     " + getC(c));
			object_code.push_back("MOV     " + t.result + ",1");
			object_code.push_back("JMP     " + getC(c + 1));
			object_code.push_back(getC(c) + ":");
			object_code.push_back("MOV     " + t.result + ",0");
			object_code.push_back(getC(c + 1) + ":");
			c++; i++;
			t = temp_code[i];
			if (t.op == "if"){
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNZ     " + codeX(x + 1));
			}
			if (t.op == "wh"){
				object_code.push_back(codeX(x) + ":");
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNE     " + codeX(x + 1));
			}
		}
		if (t.op == ">="){
			object_code.push_back("MOV     CX," + t.arg1);
			object_code.push_back("CMP     CX," + t.arg2);
			object_code.push_back("JL     " + getC(c));
			object_code.push_back("MOV     " + t.result + ",1");
			object_code.push_back("JMP     " + getC(c + 1));
			object_code.push_back(getC(c) + ":");
			object_code.push_back("MOV     " + t.result + ",0");
			object_code.push_back(getC(c + 1) + ":");
			c++; i++;
			t = temp_code[i];
			if (t.op == "if"){
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNZ     " + codeX(x + 1));
			}
			if (t.op == "wh"){
				object_code.push_back(codeX(x) + ":");
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNE     " + codeX(x + 1));
			}
		}
		if (t.op == "<="){
			object_code.push_back("MOV     CX," + t.arg1);
			object_code.push_back("CMP     CX," + t.arg2);
			object_code.push_back("JG     " + getC(c));
			object_code.push_back("MOV     " + t.result + ",1");
			object_code.push_back("JMP     " + getC(c + 1));
			object_code.push_back(getC(c) + ":");
			object_code.push_back("MOV     " + t.result + ",0");
			object_code.push_back(getC(c + 1) + ":");
			object_code.push_back("MOV     AX," + t.result);
			c++; i++;
			t = temp_code[i];
			if (t.op == "if"){
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNZ     " + codeX(x + 1));
			}
			if (t.op == "wh"){
				object_code.push_back(codeX(x) + ":");
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNE     " + codeX(x + 1));
			}

		}

		if (t.op == "&"){
			object_code.push_back("MOV     AX," + t.arg1);
			object_code.push_back("MOV     BX," + t.arg2);
			object_code.push_back("AND     AX,BX");
			object_code.push_back("MOV     " + t.result + ",AX");
			c++; i++;
			t = temp_code[i];
			if (t.op == "if"){
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNZ     " + codeX(x + 1));
			}
			if (t.op == "wh"){
				object_code.push_back(codeX(x) + ":");
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNE     " + codeX(x + 1));
			}
		}
		if (t.op == "|"){
			object_code.push_back("MOV     AX," + t.arg1);
			object_code.push_back("MOV     BX," + t.arg2);
			object_code.push_back("OR      AX,BX");
			object_code.push_back("MOV     " + t.result + ",AX");
			c++; i++;
			t = temp_code[i];
			if (t.op == "if"){
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNZ     " + codeX(x + 1));
			}
			if (t.op == "wh"){
				object_code.push_back(codeX(x) + ":");
				object_code.push_back("CMP     AX,1");
				object_code.push_back("JNE     " + codeX(x + 1));
			}
		}
		if (t.op == "we"){
			object_code.push_back("JMP     " + codeX(x));
			x++;
			object_code.push_back(codeX(x) + ":");
		}
		if (t.op == "ie"){
			object_code.push_back(codeX(x + 1) + ":");
			x++;
		}
		if (t.op == "el"){
			object_code.push_back("JMP     " + codeX(x + 1));
			object_code.push_back(codeX(x+1) + ":");
			x++;
		}
	}
}
void createObjectCode(){
	object_code.push_back("DSEG SEGMENT");
	for (auto t : identifier_table){
		switch (t.type){
		case 4:
			object_code.push_back(t.name+"      DW     0000H");
			break;
		case 5:
			object_code.push_back(t.name+"      DW     0000H");
			break;
		case 6:
			object_code.push_back(t.name+"      DB     0H");
		}
	}

	for (auto t : temp_code){
		char temp_char = t.result[0];
		//cout << temp_char << endl;
		if (temp_char == 't'&&checkTStack(t.result)){
			t_vector.push_back(t.result);
			switch (returnType(t.arg1)){
			case 3:
				object_code.push_back(t.result+"      DW      00H");
				break;
			case 4:
				object_code.push_back(t.result+"      DW      0000H" );
				break;
			case 5:
				object_code.push_back(t.result+"      DW      0000H" );
				break;
			case 6:
				object_code.push_back(t.result+"      DB      ?");
			}
		}
	}

	object_code.push_back("DSEG    ENDS");
	object_code.push_back("CSEG    SEGMENT");
	object_code.push_back("ASSUME  CS:CSEG,DS:DSEG");
	object_code.push_back("MOV     AX,DSEG");
	object_code.push_back("MOV     DS,AX");

	translateTempcode();
	object_code.push_back("MOV        AH,4CH");
	object_code.push_back("MOV        AL,0");
	object_code.push_back("INT        21H");
	object_code.push_back("CSEG       ENDS");
	object_code.push_back("END START    ");

	
}