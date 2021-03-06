// Insertion Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;

template <typename T> void insertionSort(vector<T> &vec, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = vec.at(i);
		j = i - 1;

		while (j >= 0 && vec.at(j) > key)
		{
			vec.at(j + 1) = vec.at(j);
			j = j - 1;
		}
		vec.at(j + 1) = key;
	}
}

int main() {
	vector<double> vec;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		int random = rand() % 10;
		vec.push_back(random);
	}
	insertionSort(vec, vec.size());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << " ";
	}
}