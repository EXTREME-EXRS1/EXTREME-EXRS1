/*  NPW Math
    Beta 1.0
	Build 20240812
	Lang

	迈入Beta版本！
	更改输入方式，解决输入错误问题
	大改函数：Errors; InputCheck; Calculate; main
	新增函数：Input
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <windows.h>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

char Ope='#', Op='#';					//状态,运算符
long double Ans=0;						//得数
long double N1=66, N2=666;				//数字
int Err=0;								//错误代码、
string Inp;								//输入

void Errors (){							//错误报告
	cout << "\n出现错误: 请检查输入的";
	
	if (Err>=1 && Err<=3){
	    cout << "算式的";
		switch (Err){
	        case 1:
				cout << "数字";
				break;
	        case 2:
				cout << "运算符";
				break;
	        case 3:
				cout << "格式";
	    }
		cout << "是否正常。";
	}
	if (Err==4){
	    cout << "算式的除数是否正常。";
	}
	if (Err==5){
	    cout << "内容是否正确。";
	}
	if (Err==6){
	    cout << "内容是否为空。";
	}
	if (Err==7){
		cout << "算式是否为空。";
	}
	if (Err==8){
	    cout << "算式。";
	}
	
	cout << "\n";
	Ope='m';
	Err=0;
}

bool InputCheck (){						//输入检查
    if (Op=='#' && N1==66){
		Err=7;
		return false;
	}
	if (N1==66 || N2==666 || Op=='#'){
	    Err=3;
		return false;
	}
	if (Op!='+' && Op!='-' && Op!='*' && Op!='/'){
	    Err=2;
		return false;
	}
	if (Op=='/' && N2==0){
	    Err=4;
		return false;
	}
	
	Err=0;
	return true;
}

void Input (){							//输入
    cout << "输入第一个数：";
	cin >> N1;
	cout << "输入运算符：";
	cin >> Op;
	cout << "输入第二个数：";
	cin >> N2;

	std::string n1 = std::to_string(N1);
    std::string op = std::to_string(Op);
    std::string n2 = std::to_string(N2);
	Inp = n1 + op + n2;
}

void Calculate (){						//计算
	switch (Op){
	case '+': 
		Ans=N1+N2;
		break;
	case '-':
		Ans=N1-N2;
		break;
	case '*':
		Ans=N1*N2;
		break;
	case '/':
		Ans=N1/N2;
	}
}

void Operate (){						//操作
    cout << "\n操作面板：\n";
	cout << "[c] 清除输入  [e] 退出程序  [u] 继续使用  [i] 使用指南\n";
	cin >> Ope;

	switch (Ope){
	case 'c':
		system("cls");
		Ope='m';
		break;
	case 'e':
		exit(0);
	case 'u':
		break;
	case 'i':
		cout << "\n使用指南：\n";
		cout << "我们支持+ - * /(加 减 乘 除)\n";
		Ope='m';
	default:
		if (Ope='#') Err=6; break;
		Err=5;
		Errors ();
	}

	if (Ope=='m'){
	Operate ();
	}
}

int main (){							//主函数
    cout << "*NPW Math  Beta1.0\n";
	cout << "*作者: Lang\n";
	cout << "*本开源程序可用于学习交流，也可用于商业用途\n\n";

	do {
		Input();

		if ( InputCheck() ){
		    Calculate ();
			cout << "得数: " << Ans << "\n";
		}
		else {
			Errors ();
		}

		Operate();
	} while (Ope=='u');
}