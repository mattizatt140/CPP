// Array Average.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int ary[100];
	int n;
	int sum = 0;
	
	cout << "Input size of array: "; 
	cin >> n;
	cout << endl << "Input values of array: " << endl;
	
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ": ";
		cin >> ary[i];
	}

	for (int i = 0; i < n; i++) {
		sum += ary[i];
	}

	cout << endl << "Average: " << sum / n << endl;
}

