#include "stdafx.h"
#include <iostream>
using namespace std;

double avg(int _array[], int _size)
{
	int _totalSum{};

	for (int i = 0; i < _size; i++) {

		_totalSum += _array[i];
	}

	double _totalAvg = _totalSum / _size;

	return _totalAvg;
}

int main()
{
	int _theArray[] = {1,2,3,4,5,6,7,8,9};

	// Must pass size of array to a function that uses the array;

	// https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm;

	int _sizeof = sizeof(_theArray) / sizeof(_theArray[0]);

	double newAvg = avg(_theArray, _sizeof);

	cout << newAvg << endl;
}