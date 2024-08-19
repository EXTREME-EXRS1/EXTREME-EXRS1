/*  NPW Sort
    Alpha 1.7
    Build 20240814
    Lang
*/

#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

char Ope = 'm'; //操作符
char OpA = '!'; //A选项
int N = 0; //向量元素数量
vector<int> A; //向量
int Err = 0; //错误标识

void Errors () { //错误报告
	Ope = 'm';
	cout << "\n";
	cout << "错误报告：";

	switch ( Err ) {
		case 2:
			cout << "输入的选项不正确";
			break;
		case 3:
			cout << "数组过短";
			break;
		case 1:
			cout << "输入不得为空";
			break;
	}

	Err = 0;
	cout << "\n";
}

bool Check () { //检查
	Err = 0;

	if ( OpA == '!' ) {
		Err = 1;
		return false;
	}

	if ( OpA != 'z' && OpA != 'x' ) {
		Err = 2;
		return false;
	}

	if ( N < 2 ) {
		Err = 3;
		return false;
	}

	return true;
}

void zA () { //自动填充A
	A.clear ();
	int x;

	srand ( time ( 0 ) );
	for ( int i = 0; i <= N; i++ ) {
		x = rand ();
		A.push_back ( x );
	}
}

void xA () { //手动输入A
	A.clear ();
	int x;

	cout << "\n从数组第1位开始依次输入数(用空格隔开)：";
	for ( int i = 0; i <= N; i++ ) {
		cin >> x;
		A.push_back ( x );
	}
}

void Input () { //初始自定义
	cout << "\n[z]随机生成数组";
	cout << "\n[x]自定义数组";
	cout << "\n选项：";
	cin >> OpA;
	cout << "\n数组中数的数量：";
	cin >> N;
	N -= 1; //校正
}

void Output () { //输出
	for ( int i = 0; i <= N; i++ ) {
		cout << A[i] << " ";
	}
	cout << "\b";
}

int main () { //主函数
	cout << "*NPW Sort\n*Alpha1.7\n";
	cout << "*作者: Lang\n";
	cout << "*本开源程序可用于学习交流，也可用于商业用途 :)\n\n";

	do {
		Input ();
		if ( !Check () ) {
			Errors ();
		} else {
			if ( OpA == 'z' ) {
				zA ();
				Output ();
			} else {
				xA ();
				Output ();
			}
		}
	} while ( Ope == 'u' );
	return 0;
}
