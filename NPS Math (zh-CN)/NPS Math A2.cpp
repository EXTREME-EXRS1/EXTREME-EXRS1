/*	简易计算器 作者：Lang
	Version Alpha2.0
 	Build 2024.7.24
	*因文字编码错误，导致中文乱码
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <string>
#include <windows.h>
using namespace std;

char Op;
long double Num;
std::string Input;

void Error (int type){
	cout << "\n????";

	switch (type){
		case 0: cout << "?????????0??"; break;
		case 1: cout << "??Ч???????";  break;
		case 2: cout << "??Ч????";    break;
		case 3: cout << "???????";    break;
		default: cout << "δ?????";        }
		
	cout << "\n";
	Op = 'a';
}

void Calculate (long double n1, char op, long double n2){
	switch (op){
		case '+': Num = n1 + n2;       break;
		case '-': Num = n1 - n2;       break;
		case '*': Num = n1 * n2;       break;
		case '/': 
			if (n2 != 0) Num = n1 / n2; 
            else Error(0);             break;
		default: Error(1);                  }
}

void Operate (char &op){
switch (op){
		case 'e': exit (0);
		case 'c': system("cls"); op = 'a';               break;
		case 'r': op = 'a';                              break;
		default: Error(2);                                     }
}

void cinOperate (){
		cout << "\n当前可执行操作:\n";
		cout << "[e]???   [r]???????\n"; 
		cout << "[c]???   / ???????\n"; 
		cout << "????????????";

		cin >> Op;
		Operate (Op);
		cout <<"\n"; 
}

int main (){
	cout << "欢迎使用计算器\n";
	Sleep (2000); 
	cout << "我们支持+ - * /\n";
	Sleep (2000);

	do {
		long double n1, n2;
		char op, dis;
		Op = 'n';  
		
		cout << "???????????????????????";
		if (!(cin >> n1 >> op >> n2)){
            cin.clear();
            while (cin.get (dis) && dis != '\n'){}

            Error(3);
			continue;
        }

        if (op != '+' && op != '-' && op != '*' && op != '/'){
            Error(1);
			continue;
        }

        Calculate(n1, op, n2);
        cout << n1 << op << n2 << "=" << Num;
        
        cinOperate ();
	} while (Op == 'a');
	
	return 0;
}