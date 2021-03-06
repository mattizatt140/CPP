// Array Reverse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int size;
	int ary[10];
	
	cout << "Enter size of array (1-10): ";
	cin >> size;

	if (size > 10 || size < 1) {
		cerr << "Invalid size" << endl;
	}

	if (size >= 1 && size <= 10) {
		cout << endl << "Input values of array: " << endl;
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ": ";
			cin >> ary[i];
		}

		for (int i = 0; i < size/2; i++) {
			int temp;
			temp = ary[i];
			ary[i] = ary[size - i - 1];
			ary[size - i - 1] = temp;
		}

		cout << endl << "Reversed array: " << endl;
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ": " << ary[i] << endl;
		}
	}
}

