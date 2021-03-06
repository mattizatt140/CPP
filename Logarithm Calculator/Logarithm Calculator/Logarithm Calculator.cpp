#include "stdafx.h"
#include <iostream>
#include <string>
#include "log.h"
using namespace std;

int main()
{
	string response;
	string quitLoop; // used to quit loop

	cout << "Logarithm Calculator:\n" << endl;

	cout << "Using the format {log(b)(y) = x}" << endl;

	while (quitLoop != "No" && quitLoop != "no")
	{
		cout << "Would you like to solve for 'b', 'y', or 'x'?" << endl;
		cin >> response;

		if (response == "b")
		{
			logCalc *pLog = new logCalc;
			pLog->SolveForB_Input();
		}
		else if (response == "y")
		{
			logCalc *pLog = new logCalc;
			pLog->SolveForY_Input();
		}
		else if (response == "x")
		{
			logCalc *pLog = new logCalc;
			pLog->SolveForX_Input();
		}
		cout << "\nWould you like to solve another log: Yes or No?" << endl;
		cin >> quitLoop;
	}
	cout << "\nOkay! Press any key to exit\n";
	system("PAUSE");
}
