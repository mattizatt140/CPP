// CS Module 3.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//RPM between 3524 and 8524 only

void solutionRPM(long long int rpm, int &years, long long int &finalRPM) {

	int initialRPM; //used for further loops after rpm is set to 0
	int maxRPM = (rpm * 8);
	int A;

	for (years = 1; years <= 10; years++)
	{
		int initialRPM = rpm;
		for (int i = 0; i < 10; i++)
		{
			int digit = rpm % 10;
			rpm /= 10;

			if (i == 0) {
				A = (digit * digit);
			}
			if (i > 0) {
				A += (digit * digit);
			}
			if (rpm == 0) {
				break;
			}
		}

		A *= 323;

		int digit = (initialRPM % 10); //breaks the last digit off the rpm for cycling
		int cycleLoop; //used to multiply digit by 10 for x amount of times
		int B = initialRPM / 10; //variable to add digit back to

		for (int j = 0; j < 10; j++) { //loop calculates how many placeholders there are
			initialRPM /= 10;
			if (initialRPM == 0) {
				cycleLoop = j;
				break;
			}
		}


		for (cycleLoop; cycleLoop > 0; cycleLoop--) { //multiplies digit to the largest placeholder
			digit *= 10;
		}

		B += digit; //adds digit back to B
		A += B % 100; //adds last two digits of B to A creating new RPM

		rpm = A; //sets rpm to new rpm for next year
		cout << years << ": " << rpm << endl;

		if (rpm > maxRPM) { //checks each years if max RPM has been exceeded
			finalRPM = rpm;
			cout << "Final RPM: " << finalRPM << endl;
			break;
		}
	}
}
	
int main() {
	long long rpm;
	int years;
	long long finalRPM;
	cin >> rpm;
	solutionRPM(rpm, years, finalRPM);
}