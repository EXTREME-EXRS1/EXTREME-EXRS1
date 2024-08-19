//This program was written by Lang
//All rights reserved.
//Text garbled due to text encoding error

#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

char Ops;			//operator
double Num;			//results


void error (int ops) {			//void Error Reporting
	cout << endl;
	
	switch (ops) {
		case 0:
			cout << "���󣺳�������Ϊ0��";
			break;

		case 1: 
			cout << "������Ч�������?";
			break;

		case 2:
			cout << "������Ч���룡";

		default:
			cout << "����δ֪����";
	}

	system("cls");
	Ops = 'a'; 
}

void calculate (double n1, char op, double n2) {		//void ���� 
	switch (op) {
		case '+':
			Num = n1 + n2;
			break;

		case '-':
			Num = n1 - n2;
			break;

		case '*':
			Num = n1 * n2;
			break;

		case '/':
			if (n2 != 0) Num = n1 / n2; 
			else error (0);
			break;
		
		default:
            error (1); 
	}
}

void operate () {			//void ���� 
	switch (Ops) {
		case 'e':
			exit (0); 

		case 'c':
			system("cls");
			Ops = 'a'; 
			break;

		case 'r':
			Ops = 'a';
			break;

		default:
			error (2);
	}

}

void cinoperate () {		//void �������? 
		cout << endl << endl << "��ǰ��ִ�еĲ��������ִ�Сд��:" << endl;
		cout << "[e]�˳�   [r]���¼���" << endl; 
		cout << "[c]���?   / �����ڴ�" << endl; 
		cout << "������Ĳ�����?";

		cin >> Ops;
		operate ();
}

int main () {			//int ������ 
	char op;
	double num1, num2;
	
	cout << "��ӭʹ�ü�������" << endl;
	Sleep (4000);			//ͣ���� 
	cout << "����֧��+��-��*��/" << endl;
	Sleep (2000);
	do {
		cout << endl; 
		Ops = 'n';			//���ò���Ϊ����

		cout << "������һ���ǻ���������ʽ���ÿո����?" << endl;
		cin >> num1 >> op >> num2;

		calculate (num1,op,num2);
		cout << num1 << op << num2 << "=" << Num; 

		cinoperate ();
	} while (Ops == 'a');
}
