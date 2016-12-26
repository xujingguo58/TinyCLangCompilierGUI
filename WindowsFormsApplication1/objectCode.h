

vector<string> object_code; //目标代码存储的容器

int returnType(string name){
	for (auto t : identifier_table){
		if (name == t.name){
			return t.type;
		}

	}
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

void translateTempcode(){
	for (tempCode t : temp_code){
		if (t.op == "="){
			object_code.push_back("MOV     " + t.result + "," + t.arg1);
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

	}
}
void createObjectCode(){
	object_code.push_back("DSEG SEGMENT");
	for (auto t : identifier_table){
		switch (t.type){
		case 4:
			object_code.push_back("DW      " + t.name);
			break;
		case 5:
			object_code.push_back("DD      " + t.name);
			break;
		case 6:
			object_code.push_back("DB      " + t.name);
		}
	}
	for (auto t : temp_code){
		char temp_char = t.result[0];
		//cout << temp_char << endl;
		if (temp_char == 't'){
			switch (returnType(t.arg1)){
			case 3:
				object_code.push_back("DW      " + t.result);
				break;
			case 4:
				object_code.push_back("DW      " + t.result);
				break;
			case 5:
				object_code.push_back("DD      " + t.result);
				break;
			case 6:
				object_code.push_back("DB      " + t.result);
			}
		}
	}

	object_code.push_back("DSEG    ENDS");
	object_code.push_back("CSEG    SEGMENT");
	object_code.push_back("ASSUME  CS:CSEG,DS:DSEG");
	object_code.push_back("MOV     AX,DSEG");
	object_code.push_back("MOV     DS,AX");

	translateTempcode();

	//showObjectCode();
}