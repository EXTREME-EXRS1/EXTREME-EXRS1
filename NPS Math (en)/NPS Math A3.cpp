/*	NPS Math
	Version Alpha3.0
	Build 20240724
	Lang
	*The program does not run properly due to a program error in inputting equations.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <string>
#include <windows.h>
using namespace std;

bool Err=false;					//Error flag: [true]error [false]no error
char Ope='m';					//Status flags (operators): [m] menu [c] clear [e] exit [u] continue using
string Inp="0";					// Input string: empty


void Errors (int err){								//Error reporting
	cout << "\nError: ";
	
	switch (err){
		case 0:cout << "Exceptional error, please use the program properly"; break;
		case 1:cout << "Input cannot be empty";								 break;
		case 2:cout << "Incorrect formatting of the equation";				 break;
		case 3:cout << "Unknown operator";									 break;
		case 4:cout << "The divisor cannot be 0";       	  				 break;
		case 5:cout << "Input formatting error";							 break;
	}
	cout << "\n";
	Ope='m';
	Err=false;
}

bool InputRight (const string& inp=Inp){						//Input checking; using ¡°const¡± to refer to ¡°Inp¡± prevents modification
	if (inp == "0")										Errors (1);return false;
	
	if (inp.size () != 3) 								Errors (2);return false;

	char op=inp[1];
	if (op!='+' && op!='-' && op!='*' && op!='/') 		Errors (3);return false;

	long double num2=inp[2];
	if (num2==0 && op=='/') 							Errors (4);return false;

	return true;
}

void Operate (){										//²Ù×÷²Ëµ¥
	cout << "Currently executable operations: \n";
	cout << "[c] Clear input [e] Exit program [u] Continue using\n";
	cout << "The action you want to perform: ";
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

void Calculate (string inp){							//count
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

int main (){											//main program
    cout << "*NPS Math#Alpha3.0\n";
	cout << "*Author: Lang\n";
	cout << "*This program is for learning and communication only, and is prohibited for commercial use!\n\n";

	do {
		Err=false;
		cout << "Please enter an arithmetic equation (only arithmetic equations with only one operator are supported): ";

		getline (cin, Inp);
		if (InputRight (Inp)) Calculate (Inp);
		Operate ();
		
		while (Ope == 'm') Operate ();
		if (Ope == 'e') exit (0);
	} while (Ope=='u' || Ope!='m');
}
