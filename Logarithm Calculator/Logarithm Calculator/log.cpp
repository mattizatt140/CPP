#include "stdafx.h"
#include "log.h"
#include <iostream>

void logCalc::SolveForX_Input()
{
	cout << "\nInput variables 'b' and 'y' to solve for 'x' (integers only)" << endl;

	cout << endl;

	cout << "Input 'b': ";
	cin >> _base;
	cout << "Input 'y': ";
	cin >> _result;

	logCalc *plogCalc = new logCalc;
	plogCalc->SolveForX(_base, _result); //functions are seperate for clarity
}

void logCalc::SolveForX(int _base, int _result)
{
	for (int i = 1; i < 25; i++)
	{
		_answer *= _base;
		if (_answer == _result)
		{
			cout << endl;
			cout << "x = " << i << endl;
			cout << "log" << _base << "(" << _result << ")";
			cout << " = " << i << endl;
			cout << "The equivelent of " << _base << "^";
			cout << i << " = " << _result << endl;
			break;
		}
		else if (_base != 1 && _result == 1)
		{
			cout << endl;
			cout << "x = 0" << endl;
			cout << "log" << _base << "(1)" << " = 0" << endl;
			cout << "The equivelent of " << _base << "^";
			cout << "0" << " = " << _result << endl;
			break;
		}
		else if (_answer > _result)
		{
			cout << "Error: Integer Solutions Only" << endl;
			break;
		}
	}
}

void logCalc::SolveForB_Input()
{
	cout << "\nInput variables 'y' and 'x' to solve for 'b' (integers only)" << endl;

	cout << endl;

	cout << "Input 'y': ";
	cin >> _result;
	cout << "Input 'x': ";
	cin >> _exponent;

	logCalc *plogCalc = new logCalc;
	plogCalc->SolveForB(_result, _exponent); //functions are seperated for clarity
}

void logCalc::SolveForB(int _result, int _exponent)
{
	for (int i = 0; i < 100000; i++)
	{
		int _initialBase = i; //done to reduce problems with if statement
		for (int j = 1; j < _exponent; j++)
		{
			_initialBase *= i;
		}
			if (_initialBase == _result)
			{
				cout << endl;
				cout << "b = " << i << endl;
				cout << "log" << i << "(" << _result << ")";
				cout << " = " << _exponent << endl;
				cout << "The equivelent of " << i << "^";
				cout << _exponent << " = " << _result << endl;
				break;
			}
			else if (_initialBase > _result)
			{
				cout << endl;
				cerr << "Error: Integer Solutions Only" << endl;
				break;
			}
	}
}

void logCalc::SolveForY_Input()
{
	cout << "\nInput variables 'b' and 'x' to solve for 'y' (integers only)" << endl;

	cout << endl;

	cout << "Input 'b': ";
	cin >> _base;
	cout << "Input 'x': ";
	cin >> _exponent;

	logCalc *plogCalc = new logCalc;
	plogCalc->SolveForY(_base, _exponent); //functions are seperated for clarity
}

void logCalc::SolveForY(int _base, int _exponent)
{
	for (int i = 0; i < _exponent; i++)
	{
		_answer *= _base;
	}
	cout << endl;
	cout << "y = " << _answer << endl;
	cout << "log" << _base << "(" << _answer << ")";
	cout << " = " << _exponent << endl;
	cout << "The equivelent of of " << _base << "^";
	cout << _exponent << " = " << _answer << endl;
}

