/*  NPS Math
    Beta 1.0
	Build 20240812
	Lang

	Step into Beta version!
	Changed the input method to solve the input error problem
	Overhauled functions: Errors; InputCheck; Calculate; main
	New function: Input
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

char Ope='#', Op='#';					//State, Operator
long double Ans=0;						//Ans
long double N1=66, N2=666;				//Number
int Err=0;								//Error code
string Inp;								//Input

void Errors (int err){								//Error reporting
	cout << "\nError: ";
	
	switch (err){
		case 1:cout << "Please check the numbers entered";						break;
		case 2:cout << "Please check the entered operator";				 		break;
		case 3:cout << "Please check the input format";							break;
		case 4:cout << "Please check the divisor of the entered equation";      break;
		case 5:cout << "Please check your input";							 	break;
		case 6:cout << "Please check if the input is empty";					break;
		case 7:cout << "Please check if the entered equation is empty";			break;
		case 8:cout << "Please check the entered equation";
	}
	cout << "\n";
	Ope='m';
	Err=false;
}

bool InputCheck (){						//Input checking
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

void Input (){							//Input
    cout << "Enter the first number: ";
	cin >> N1;
	cout << "Input Operator: ";
	cin >> Op;
	cout << "Enter the second number: ";
	cin >> N2;

	std::string n1 = std::to_string(N1);
    std::string op = std::to_string(Op);
    std::string n2 = std::to_string(N2);
	Inp = n1 + op + n2;
}

void Calculate (){						//Count
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

void Operate (){						//Manipulate
    cout << "\nOperator Panel:\n";
	cout << "[c] Clear input [e] Exit program [u] Continue [i] User's guide\n";
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
		cout << "\nUser's guide£º\n";
		cout << "We support + - * / (addition, subtraction, multiplication, division)\n";
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

int main (){							//Ö÷º¯Êý
    cout << "*NPS Math  Beta1.0\n";
	cout << "*Author: Lang\n";
	cout << "*This open source program can be used for learning and communication, also can be used for commercial purposes\n\n";

	do {
		Input();

		if ( InputCheck() ){
		    Calculate ();
			cout << "Score: " << Ans << "\n";
		}
		else {
			Errors ();
		}

		Operate();
	} while (Ope=='u');
}
