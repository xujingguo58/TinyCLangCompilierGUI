

#include<vector>
#include"token.h"
#include"semantic.h"
#include"symbolTable.h"
#include"optimize.h"
#include"objectCode.h"


//定义函数
int relation_operator();  //关系运算符
int arithmetic_expression();//算数表达式
int logic_expression();  //<逻辑表达式>
int condition();  //<条件>
int conditional_statement();  //条件语句
int loop_statement();    //循环(while)语句
int variable_declatation(); //<变量声明语句>
int code_block();
int program();
int main_function();
int entrance();
int else_statement();
int E();
int F();
int T();
int assignment();  //<赋值>
int char_constant();//<字符常量>
int declaration_or_assign();//<声明或赋值>
int if_assign(); //<是否赋值>
int branch_program();  //<分程序>
//int p;//token指针
string now_name = "";   //分别是当前token的值、序列号，源程序所在行
int now_number = 0;
int line = 1;


void nextW(){
	now_name = token[p].token_name;
	now_number = token[p].token_number;
	line = token[p].line;
	p++;
}
void lastW(){
	p--;
	now_number = token[p].token_number;
	line = token[p].line;
}
int if_assign(){
	semantic_stack.push(now_name);
	//首先判断是否存在定义，若存在，还要再判断是否是同一个类型，如果没错误，添加标识符表
	if (checkIdentifierTable(now_name, type_stack.top()) == 1){    //说明重定义
		return 3001;
	}

	else {  //若标识符表没有，则添加到标识符表中

		addIdentifierTable(now_name, type_stack.top());
	}
	nextW();
	if (now_number == 20) {  //现在是"=",说明是在声明时直接赋值

		nextW();
		int result = assignment();
		if (result >= 1000) return result;
		return 1;

	}
	else if (now_number == 43 || now_number == 31){  //空，不赋值
		return 1;
	}
	else
		return 1013; //need ';'
}
int declaration_or_assign(){
	int result = if_assign();
	if (result >= 1000) return result;
	else
		return 1;

}
int variable_declatation(){     //变量声明
	int result = declaration_or_assign();
	if (result >= 1000) return result;
loop_assign:
	//nextW();
	if (now_number == 31){  //, 表示继续赋值
		nextW();
		result = declaration_or_assign();
		if (result >= 1000) return result;
		//nextW();
		if (now_number == 31) goto loop_assign;
		else if (now_number == 43) return 1;
		else
			return 1013; //need ';'
	}
	else if (now_number == 43) return 1;
	else
		return 1013;  //need ';'
}
int assignment(){        //<赋值>
	if (now_number == 0 || now_number == 3){  //如果是常数或标识符，则为算数表达式
		int result = arithmetic_expression();
		if (result >= 1000) return result;
		string arg1 = semantic_stack_pop();
		string semantic_result = semantic_stack_pop();
		send("=", arg1, "_", semantic_result);
		return 1;
	}
	else if (now_number == 1){  //如果是字符，则为字符常量
		send("=", now_name, "_", semantic_stack_pop());

		nextW();

		return 1;
	}
	else
		return 1200;  //表达式右值错误；
}
int relation_operator(){
	if (now_number == 20 || now_number == 21 || now_number == 22 || now_number == 23 || now_number == 24 || now_number == 25 || now_number == 39 || now_number == 40)
		return 1;
	else
		return 1007;//neeed operator
}
int F(){
	int result;
	if (now_number == 3 || now_number == 0){
		semantic_stack.push(now_name);  //压入语义栈
		nextW();
	}
	else{
		if (now_number == 37){
			nextW();
			result = E();
			if (result >= 1000) return result;
			if (now_number == 38) {
				nextW();
				return 1;
			}
			else
				return 1008;//error1
		}
		else
			return 1009;//error2
	}

}
int T(){
	int result = F();
	if (result >= 1000) return result;
loop_F:
	if (now_number == 28 || now_number == 29){
		operator_stack.push(now_name);  //操作符入操作符栈
		nextW();
		result = F();
		if (result >= 1000) return result;
		GEQ();    //生成算数表达式四元式
		goto loop_F;
	}
	return 1;
}
int E(){
	int result;
	result = T();
	if (result >= 1000) return result;
loop_T:
	if (now_number == 26 || now_number == 27){
		operator_stack.push(now_name);  //操作符入操作符栈
		nextW();
		result = T();
		GEQ();    //生成算数表达式四元式
		if (result >= 1000) return result;
		goto loop_T;
	}
	return 1;
}
int arithmetic_expression(){
	int result = E();
	if (result >= 1000) return result;
	else
		return 1;
}
int logic_expression(){
	//nextW();
	int result = arithmetic_expression();
	if (result >= 1000) return result;
	nextW();
	result = relation_operator();
	if (result >= 1000) return result;
	nextW();
	result = arithmetic_expression();
	if (result >= 1000) return result;
	return 1;
}
int condition(){
	if (now_number == 37){
		nextW();
		//int result=logic_expression();
		//if (result >= 1000) return result;
		if (now_number == 3 || now_number == 0){
			semantic_stack.push(now_name);
			nextW();
			int result = relation_operator();
			if (result >= 1000) return result;
			operator_stack.push(now_name);
			nextW();
			if (now_number == 3 || now_number == 0) {
				semantic_stack.push(now_name);
				nextW();
				if (now_number == 38){
					GEQ();
					return 1;
				}
				else
					return 1004;//need ')'
			}
			else
				return 1011;  //右值类型错误
		}
		else
			return 1010;  //左值类型错误
		nextW();
		if (now_number == 38) return 1;
		else
			return 1004;
	}
	else
		cout << now_number;
	return 1003;  //neeed '('
}
int else_statement(){  //<else程序>
	nextW();
	int result = branch_program();
	if (result >= 1000) return result;
	return 1;
}
int conditional_statement(){   //条件语句

	//nextW();
	int result = condition();
	//int result=program();
	if (result >= 1000) return result;
	send("if", semantic_stack_pop(), "_", "_");
	nextW();
	result = branch_program();
	if (result >= 1000) return result;
	//nextW();
	nextW();
	if (now_number == 10){
		send("el", "_", "_", "_");
		//send("ie", "_", "_", "_");  //else
		result = else_statement();
		if (result >= 1000) return result;
		else{
			//send("el", "_", "_", "_");
			return 1;
		}
	}
	lastW();
	return 1;

}
int loop_statement(){   //循环(while)语句
	int result = condition();
	//int result=program();
	if (result >= 1000) return result;
	send("wh", semantic_stack_pop(), "_", "_");
	nextW();
	result = branch_program();
	if (result >= 1000) return result;
	return 1;
}
int code_block(){
	if (now_number == 34) {
		lastW();
		return 1;//说明{}之间没有代码
	}
	else{
		if (now_number == 4 || now_number == 5 || now_number == 6){  //是类型，说明是变量声明语句
			cout << "声明语句" << endl;
			type_stack.push(now_number);
			nextW();
			//semantic_stack.push(now_name);
			int result = variable_declatation();
			if (result >= 1000)
				return result;
			type_stack.pop();
		}
		else if (now_number == 0){  //标识符，说明是赋值语句
			//判断标识符是否的定义
			if (checkIdentifierTable(now_name, now_number) == 0){  //说明未定义 
				cout << "here";
				return 3002;
			}
			semantic_stack.push(now_name);
			cout << "赋值语句";
			nextW();
			if (now_number == 20){
				nextW();
				int result = assignment();
				if (result >= 1000) return result;
				if (now_number != 43) {
					//nextW();
					return 1013; //need ';'
				}
			}
			else
				return 1012;//need '='
		}
		else if (now_number == 9){  //if 说明是if语句
			cout << "if语句" << endl;
			nextW();
			int result = conditional_statement();
			if (result > 1000) return result;
			send("ie", "_", "_", "_");
		}
		else if (now_number == 12){  //while 循环语句
			cout << "while语句" << endl;
			nextW();
			int result = loop_statement();
			if (result >= 1000) return result;
			send("we", "_", "_", "_");
		}
		else if (now_number == 19){  //return 
			nextW();
			if (now_name == "1" || now_name == "0"){
				nextW();
				if (now_number == 43){
					//nextW();
					return 1;
				}
				else
					return 1013;//need ';'
			}
		}
		else{   //未识别语句
			cout << "1100";
			return 1100;
		}
		cout << "一个语句分析结束" << endl;
		nextW();
		//cout << now_number << endl;
		code_block();
	}

}
int branch_program(){
	if (now_number == 33){
		nextW();
		if (now_number == 34)  return 1;//现在为{}说明中间没有代码
		int result = code_block();
		if (result >= 1000) return result;
		nextW();
		if (now_number == 34) {
			//cout << "right";
			//return 1;
		}
		else
		{
			cout << "error here" << p; return 1006; //need '}'
		}
	}
	else
	{
		return 1005; //need '{'
	}
}
int program(){
	if (now_number == 33){
		nextW();
		if (now_number == 34)  return 1;//现在为{}说明中间没有代码
		int result = code_block();
		if (result > 1000) return result;
		nextW();
		if (now_number == 34) {
			//cout << "right";
			//return 1;
		}
		else
		{
			cout << "error here" << p; return 1006; //need '}'
		}
	}
	else
	{
		return 1005; //need '{'
	}
}
int main_function(){
	if (now_number == 4){
		nextW();
		if (now_number == 07){  //是main，将main生成四元式
			send("main", "_", "_", "_");
			nextW();
			if (now_number == 37){
				nextW();
				if (now_number == 38){
					nextW();
					int result = program();
					if (result > 1000) return result;
					result = checkTempCode();   //检查中间代码
					if (result > 1000) return result;
				}
				else
					return 1004;//need ')'
			}
			else
				return 1003;//need '('
		}
		else
			return 1002; //need 'main'
	}
	else
		return 1001;//main函数需要类型 
}
int entrance(){
	nextW();
	if (now_number == 18)
	{
		nextW();
		if (now_number == 101){
			nextW();
			if (now_number == 22){
				nextW();
				if (now_number == 100){
					nextW();
					if (now_number == 21){
						nextW();
						int result = main_function();
						return result;
					}
					else
						return 1000;
				}
				else
					return 1000;
			}
			else
				return 1000;
		}
		else
			return 1000;

	}
	else{
		return 1000;//need ‘#’
	}
}


int  syntax(){
	p = 0;
	line = 1;
	int result = entrance();
	if (result >= 1000)
		return result;
	else
		return 1;
}
