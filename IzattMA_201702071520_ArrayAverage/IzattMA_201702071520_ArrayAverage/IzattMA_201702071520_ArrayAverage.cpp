#include "stdafx.h"
#include <iostream>
using namespace std;

double avg(int _array[])
{
	int _totalSum{};

	int _sizeof = sizeof(_array);


	for (int i = 0; i <= _sizeof ; i++) {

		_totalSum += _array[i];
	}
	
	double _totalAvg = _totalSum / _sizeof;
	
	return _totalAvg;
}

int main()
{
	int _newArray[] = { 1,2,3,4,5 };
	double _newAvg = avg(_newArray);
	cout << _newAvg << endl;
}