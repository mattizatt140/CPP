// CS Module 3.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void detectHappy(int number, int &finalNumber, int &cycle_no) {

	int sum;
	
	for (int j = 1; j <= 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			int digit = number % 10;
			number /= 10;

			if (i == 0) {
				sum = (digit * digit);
			}
			if (i > 0) {
				sum += (digit * digit);
			}
			if (number == 0) {
				break;
			}
		}
		
		cycle_no = j;
		number = sum;
		
		cout << j << ": " << number << endl;
		
		if (sum == 1) {
			finalNumber = sum;
			break;
		}
		if (j == 10) {
			finalNumber = sum;
		}
	}

	cout << "\nFinal Number: " << finalNumber << endl;
	cout << "Loop count: " << cycle_no << endl;
}

int main()
{
	int num, result, cycle;
	std::cin >> num;
	detectHappy(num, result, cycle);
}


