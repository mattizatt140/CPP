// Prime Number Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void isPrime() {
	
	double i, k, factor;
	int size;
	
	cout << "Max Number: ";
	cin >> size;

	for (i = 1; i <= size; i++) {
		for (k = 1; k < (i + 1); k++) {
			factor = i / k;
			if (factor == static_cast<int>(factor) && (factor == 1) && ((factor != i) || (i == 1))) {
				cout << i << ": Prime" << endl;
				break;
			}
			if (factor == static_cast<int>(factor) && (factor != 1) && (factor != i)) {
				cout << i << ": Composite" << endl;
				break;
			}
			
		}
	}
}
int main()
{
	isPrime();
}

