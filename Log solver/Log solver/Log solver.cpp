#include "stdafx.h"
#include <iostream>
#include "logClass.h"
#include <string>

int main()
{
	logCalc *plogCalc1 = new logCalc;
	plogCalc1->_logSolve();
	delete plogCalc1;
	
	cout << endl;
	
	string *pInput = new string;
	cout << "Would you like to solve another Logarithm?" << endl;
	cout << "Yes or No" << endl;
	cin >> *pInput;

	while (*pInput == "Yes" || *pInput == "yes")
	{
		logCalc *plogCalc1 = new logCalc;
		cout << endl;
		plogCalc1->_logSolve1();
		cout << endl;
		cout << "Would you like to solve another Logarithm?" << endl;
		cout << "Yes or No" << endl;
		cin >> *pInput;
	}
	if (*pInput != "Yes" || *pInput != "yes")
	{}
	
	system("PAUSE");
}