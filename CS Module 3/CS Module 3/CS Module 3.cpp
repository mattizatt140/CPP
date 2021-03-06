#include "stdafx.h"
#include <iostream>


int main()
{
	int num, result;
	std::cin >> num;
	squaredSum(num, result);
}

void squaredSum(int sqdnumber, int &sqdNumber_result) {
	
	int digit;

	for (int i = 0; i < 10; i++) //the loop cycles through digits 
								 //the counter is set 0 - 9
								 //because an int can store 10 digits max
	{
		digit = sqdnumber % 10;
		sqdnumber /= 10;

		if (i == 0) {
			sqdNumber_result = (digit * digit);
		}
		if (i > 0) {
			sqdNumber_result += (digit * digit);
		}
		if (sqdnumber == 0) {
			break;
		}
	}
	std::cout << sqdNumber_result << std::endl;
}