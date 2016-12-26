

#include<vector>
#include"token.h"
#include"semantic.h"
#include"symbolTable.h"
#include"optimize.h"

//���庯��
int relation_operator();  //��ϵ�����
int arithmetic_expression();//��������ʽ
int logic_expression();  //<�߼�����ʽ>
int condition();  //<����>
int conditional_statement();  //�������
int loop_statement();    //ѭ��(while)���
int variable_declatation(); //<�����������>
int code_block();
int program();
int main_function();
int entrance();
int else_statement();
int E();
int F();
int T();
int assignment();  //<��ֵ>
int char_constant();//<�ַ�����>
int declaration_or_assign();//<������ֵ>
int if_assign(); //<�Ƿ�ֵ>
int branch_program();  //<�ֳ���>
//int p;//tokenָ��
string now_name = "";   //�ֱ��ǵ�ǰtoken��ֵ�����кţ�Դ����������
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
	//�����ж��Ƿ���ڶ��壬�����ڣ���Ҫ���ж��Ƿ���ͬһ�����ͣ����û�������ӱ�ʶ����
	if (checkIdentifierTable(now_name, type_stack.top()) == 1){    //˵���ض���
		return 3001;
	}

	else {  //����ʶ����û�У������ӵ���ʶ������

		addIdentifierTable(now_name, type_stack.top());
	}
	nextW();
	if (now_number == 20) {  //������"=",˵����������ʱֱ�Ӹ�ֵ

		nextW();
		int result = assignment();
		if (result >= 1000) return result;
		return 1;

	}
	else if (now_number == 43 || now_number == 31){  //�գ�����ֵ
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
int variable_declatation(){     //��������
	int result = declaration_or_assign();
	if (result >= 1000) return result;
loop_assign:
	//nextW();
	if (now_number == 31){  //, ��ʾ������ֵ
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
int assignment(){        //<��ֵ>
	if (now_number == 0 || now_number == 3){  //����ǳ������ʶ������Ϊ��������ʽ
		int result = arithmetic_expression();
		if (result >= 1000) return result;
		string arg1 = semantic_stack_pop();
		string semantic_result = semantic_stack_pop();
		send("=", arg1, "_", semantic_result);
		return 1;
	}
	else if (now_number == 1){  //������ַ�����Ϊ�ַ�����
		send("=", now_name, "_", semantic_stack_pop());

		nextW();

		return 1;
	}
	else
		return 1200;  //����ʽ��ֵ����
}
int relation_operator(){
	if (now_number == 20 || now_number == 21 || now_number == 22 || now_number == 23 || now_number == 24 || now_number == 25)
		return 1;
	else
		return 1007;//neeed operator
}
int F(){
	int result;
	if (now_number == 3 || now_number == 0){
		semantic_stack.push(now_name);  //ѹ������ջ
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
		operator_stack.push(now_name);  //�������������ջ
		nextW();
		result = F();
		if (result >= 1000) return result;
		GEQ();    //������������ʽ��Ԫʽ
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
		operator_stack.push(now_name);  //�������������ջ
		nextW();
		result = T();
		GEQ();    //������������ʽ��Ԫʽ
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
				return 1011;  //��ֵ���ʹ���
		}
		else
			return 1010;  //��ֵ���ʹ���
		nextW();
		if (now_number == 38) return 1;
		else
			return 1004;
	}
	else
		cout << now_number;
	return 1003;  //neeed '('
}
int else_statement(){  //<else����>
	nextW();
	int result = branch_program();
	if (result >= 1000) return result;
	return 1;
}
int conditional_statement(){   //�������

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
		send("ie", "_", "_", "_");  //else
		result = else_statement();
		if (result >= 1000) return result;
		else{
			send("el", "_", "_", "_");
			return 1;
		}
	}
	lastW();
	return 1;

}
int loop_statement(){   //ѭ��(while)���
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
		return 1;//˵��{}֮��û�д���
	}
	else{
		if (now_number == 4 || now_number == 5 || now_number == 6){  //�����ͣ�˵���Ǳ����������
			cout << "�������" << endl;
			type_stack.push(now_number);
			nextW();
			//semantic_stack.push(now_name);
			int result = variable_declatation();
			if (result >= 1000)
				return result;
			type_stack.pop();
		}
		else if (now_number == 0){  //��ʶ����˵���Ǹ�ֵ���
			//�жϱ�ʶ���Ƿ�Ķ���
			if (checkIdentifierTable(now_name, now_number) == 0){  //˵��δ���� 

				return 3002;
			}
			semantic_stack.push(now_name);
			cout << "��ֵ���";
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
		else if (now_number == 9){  //if ˵����if���
			cout << "if���" << endl;
			nextW();
			int result = conditional_statement();
			if (result > 1000) return result;
			send("ie", "_", "_", "_");
		}
		else if (now_number == 12){  //while ѭ�����
			cout << "while���" << endl;
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
		else{   //δʶ�����
			cout << "1100";
			return 1100;
		}
		cout << "һ������������" << endl;
		nextW();
		//cout << now_number << endl;
		code_block();
	}

}
int branch_program(){
	if (now_number == 33){
		nextW();
		if (now_number == 34)  return 1;//����Ϊ{}˵���м�û�д���
		int result = code_block();
		if (result > 1000) return result;
		nextW();
		if (now_number == 34) {
			//cout << "right";
			return 1;
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
		if (now_number == 34)  return 1;//����Ϊ{}˵���м�û�д���
		int result = code_block();
		if (result > 1000) return result;
		nextW();
		if (now_number == 34) {
			//cout << "right";
			return 1;
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
		if (now_number == 07){  //��main����main������Ԫʽ
			send("main", "_", "_", "_");
			nextW();
			if (now_number == 37){
				nextW();
				if (now_number == 38){
					nextW();
					program();
					//int result = checkTempCode();   //����м����
					//if (result > 1000) return result;
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
		return 1001;//main������Ҫ���� 
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
						main_function();
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
		return 1000;//need ��#��
	}
}


int  syntax(){
	p = 0;
	int result = entrance();
	if (result >= 1000)
		return result;
	else
		return 1;
}