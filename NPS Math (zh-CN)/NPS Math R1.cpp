#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
char Ope='#', Op='#';
long double Ans=0;
long double N1=55.5, N2=316.001;
int Err=0;
void Errors (){
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
bool InputCheck (){
    if (Op=='#' && N1==55.5){
		Err=7;
		return false;
	}
	if (N1==55.5 || N2==316.001 || Op=='#'){
	    Err=3;
		return false;
	}
	if (Op!='+' && Op!='-' && Op!='*' && Op!='/' && Op!='^' && Op!='q' && Op!='i' && Op!='o' && Op!='c' && Op!='s' && Op!='a'){
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
void Input (){
    cout << "输入第一个数：";
	cin >> N1;
	cout << "输入运算符：";
	cin >> Op;
	cout << "输入第二个数：";
	cin >> N2;
}
void Calculate (){
	switch (Op){
        case '+': Ans=N1+N2; break;
        case '-': Ans=N1-N2; break;
        case '*': Ans=N1*N2; break;
        case '/': Ans=N1/N2; break;
        case '^': Ans=pow (N1, N2); break;
        case 'q': Ans=sqrt (N1); break;
        case 'i': Ans=sin (N1); break;
		case 'o': Ans=cos (N1); break;
        case 'c': Ans=acos (N1); break;
        case 's': Ans=asin (N1); break;
        case 'a': Ans=tan (N1);
    }
}
void Operate (){					
    Err=0;
    cout << "操作面板：\n";
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
		cout << "+ - * / ^(加 减 乘 除 幂)\n";
		cout << "q i o c s a(开方 正弦 余弦 反余弦 反正弦 正切)\n";
		Ope='m';
	case '#':
        Err=6;
    default:
		Err=5;
	}
    if (Err!=0) Errors ();
	if (Ope=='m') Operate ();
}
int main (){
    cout << "NPS Math\n正式版 1.3\n作者：Lang\n本开源程序可用于任何用途，但须标明来源及作者\n\n";
	do {
		Input();
		if (InputCheck()){
		    Calculate ();
			cout << "得数: " << Ans << "\n\n";
		}
		else Errors ();
		Operate();
	} while (Ope=='u');
}
