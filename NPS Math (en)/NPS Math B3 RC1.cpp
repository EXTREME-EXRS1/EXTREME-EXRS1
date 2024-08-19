/*  NPS Math
    Beta 3.2
	RC 1.0
	Build 20240815
	Lang
*/

#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

char Ope='#', Op='#';
long double Ans=0;
long double N1=55.5, N2=666;
int Err=0;

void Errors (){
	cout << "\nError: ";
	
	switch (Err){
		case 1:cout << "Please check the numbers entered";						break;
		case 2:cout << "Please check the entered operator";				 		break;
		case 3:cout << "Please check the input format";							break;
		case 4:cout << "Please check the divisor of the entered equation";      break;
		case 5:cout << "Please check your input";							 	break;
		case 6:cout << "Please check if the input is empty";					break;
		case 7:cout << "Please check if the entered equation is empty";
	}
	cout << "\n";
	Ope='m';
	Err=false;
}

bool InputCheck (){
    if (Op=='#' && N1==55.5){
		Err=7;
		return false;
	}
	if (N1==55.5 || N2==666 || Op=='#'){
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
	cout << "Enter the first number:";
	cin >> N1;
	cout << "Input Operator:";
	cin >> Op;
	cout << "Enter the second number:";
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
    cout << "Operator Panel:\n";
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
		cout << "\nUser's guide: \n";
		cout << "+ - * / ^ (the powers of addition, subtraction, multiplication and division)\n";
		cout << "q i o c s a (square, sine, cosine, inverse cosine, arctangent, tangent)\n";

		Ope='m';
	case '#':
        Err=6;
    default:
		Err=5;
	}

    if (Err!=0){
        Errors ();
    }
	if (Ope=='m'){
    	Operate ();
	}
}

int main (){
    cout << "NPS Math\nBeta 3.2\nRC 1.0";
	cout << "Author: Lang\n";
	cout << "This open source program can be used for learning and communication as well as commercial use :)\n\n";

	do {
		Input();

		if ( InputCheck() ){
		    Calculate ();
			cout << "Score: " << Ans << "\n\n";
		}
		else {
			Errors ();
		}

		Operate();
	} while (Ope=='u');
}
