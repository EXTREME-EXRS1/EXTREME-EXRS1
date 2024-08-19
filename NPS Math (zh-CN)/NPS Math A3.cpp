/*	NPS Math
	Version Alpha3.0
	Build 20240724
	Lang
	*因输入算式的程序错误，导致程序无法正常运行
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <string>
#include <windows.h>
using namespace std;

bool Err=false;					//错误标志：[true]有错误 [false]无错误
char Ope='m';					//状态标志(操作符)：[m]菜单 [c]清除 [e]退出 [u]继续使用
string Inp="0";					//输入的字符串：空


void Errors (int err){								//错误报告
	cout << "\n错误：";
	
	switch (err){
		case 0:cout << "异常错误，请正经地使用程序"; break;
		case 1:cout << "输入不能为空";				break;
		case 2:cout << "算式格式错误";				break;
		case 3:cout << "未知运算符";				break;
		case 4:cout << "除数不能为零";       	  	break;
		case 5:cout << "输入格式错误";				break;
	}
	cout << "\n";
	Ope='m';
	Err=false;
}

bool InputRight (const string& inp=Inp){						//输入检查; const引用Inp防止修改
	if (inp == "0")										Errors (1);return false;
	
	if (inp.size () != 3) 								Errors (2);return false;

	char op=inp[1];
	if (op!='+' && op!='-' && op!='*' && op!='/') 		Errors (3);return false;

	long double num2=inp[2];
	if (num2==0 && op=='/') 							Errors (4);return false;

	return true;
}

void Operate (){										//操作菜单
	cout << "当前可执行操作：\n";
	cout << "[c] 清除输入   [e] 退出程序   [u] 继续使用\n";
	cout << "你要执行的操作：";
	cin >> Ope;
	cout << "\n";

	switch (Ope){
		case 'c': system("cls"); Ope='m';		break;
		case 'e': 								break;
		case 'u': 								break;
		default: Errors (5);					break;
	}
	getchar ();
}

void Calculate (string inp){							//计算
	long double num1=inp[0];
	long double num2=inp[2];
	char op=inp[1];

	switch (op){
		case '+': cout << num1 << " + " << num2 << " = " << num1+num2 << "\n"; break;
		case '-': cout << num1 << " - " << num2 << " = " << num1-num2 << "\n"; break;
		case '*': cout << num1 << " * " << num2 << " = " << num1*num2 << "\n"; break;
		case '/': cout << num1 << " / " << num2 << " = " << num1/num2 << "\n"; break;
	}
}

int main (){											//主程序
    cout << "*NPS Math#Alpha3.0\n";
	cout << "*作者：Lang\n";
	cout << "*本程序仅用于学习交流，禁止用于商业用途！\n\n";

	do {
		Err=false;
		cout << "请输入算式(只支持仅一个运算符的算式)：";

		getline (cin, Inp);
		if (InputRight (Inp)) Calculate (Inp);
		Operate;
		
		while (Ope == 'm') Operate;
		if (Ope == 'e') exit (0);
	} while (Ope=='u' || Ope!='m');
}
