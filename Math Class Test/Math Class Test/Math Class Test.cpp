#include "stdafx.h"
#include <iostream>
#include "math.h"
#include <string>
using namespace std;

int main()
{
	math test; 
	string exit;
	int x;
	int y;
	
	cout << "Input x" << endl;
	cin >> x;
	cout << "Input y" << endl;
	cin >> y;
	
	int addTest = test.add(x, y);
	int subTest = test.sub(x, y);
	int multiTest = test.multi(x, y);
	double divideTest = test.divide(x, y);
	int expTest = test.exp(x, y);
	
	cout << "x + y = " << addTest << endl << "x - y = " << subTest << endl;
	cout << "x * y = " << multiTest << endl << "x / y = " << divideTest << endl << "x ^ y = " << expTest << endl;

	cout << "Press '1' then 'Enter' to exit" << endl;
	cin >> exit; 
	
	while (exit != "1")
	{
		cout << "Press '1' then 'Enter' to exit" << endl;
		cin >> exit;
	}
}


