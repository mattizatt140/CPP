#include "stdafx.h"
#include <iostream>
using namespace std;

int avg(int _array[])
{ 
	int totalSum;
	for (int i = 0; i < sizeof(_array); i++) {
		totalSum += _array[i];
	}
	int totalAvg = totalSum / sizeof(_array);
	return totalAvg;
}

int main()
{
	int newArray[] = { 1,2,3,4,5 };
	int newAvg = avg(newArray);
	cout << newAvg << endl;
}