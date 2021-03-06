// OOP Module 2 GPA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct rational {
	int numerator;
	int denominator;
};

void reduce(rational *inputrational, rational *outputrational) {
	
	for (int i = (inputrational->denominator) * (inputrational->numerator); i > 1; i--) {
		if ((inputrational->denominator % i == 0) && (inputrational->numerator % i == 0)) {
			outputrational->denominator = (inputrational->denominator) / i;
			outputrational->numerator = (inputrational->numerator) / i;
			break;
		}
	}
}

bool isEqual(rational num1, rational num2) {
	reduce(&num1, &num1);
	reduce(&num2, &num2);

	if ((num1.numerator == num2.numerator) && (num1.denominator) == (num2.denominator)) {
		return true;
	}
	else { return false; }
}

int main() {
	int result;
	struct rational num1, num2;
	cout << "Enter Details of Number 1 " << endl;
	cout << "Enter Numerator :" << endl;
	cin >> num1.numerator;
	cout << "Enter Denominator :" << endl;
	cin >> num1.denominator;
	cout << "Enter Details of Number 2 " << endl;
	cout << "Enter Numerator :" << endl;
	cin >> num2.numerator;
	cout << "Enter Denominator :" << endl;
	cin >> num2.denominator;
	result = isEqual(num1, num2);     //to check rational 'num1' is equal to rational 'num2' 
	if (result == true)
		cout << "Both rational numbers are equal" << endl;
	else
		cout << "Both rational numbers are not equal" << endl;
	return 0;
}

