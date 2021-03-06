// Counting Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

template <typename T> T returnMax(std::vector<T> &vector) {
	T Max = 0;
	for (int i = 0; i < vector.size(); i++) {
		if (vector.at(i) > Max) {
			Max = vector.at(i);
		}
	}
	return Max;
}

template <typename T> void countSort(std::vector<T> &vector) {
	std::vector<T> count(returnMax(vector) + 1);
	
	try {
		for (int i = 0; i < count.size(); i++) {
			count.at(i) = 0;
		}
		
		for (int i = 0; i < vector.size(); i++) {
			count.at(vector[i])++;
		}

		int c = 0;

		for (int i = 0; i < count.size(); i++) {
			for (int j = 0; j < count.at(i); j++) {
				vector.at(c) = i;
				c++;
			}
		}
	}
	catch (...) {
		throw;
	}
}

int main() {
	int n, value;
	std::cin >> n;
	std::vector<int> myVector;
	{
		try {
			for (int i = 0; i < n; i++) {
				std::cin >> value;
				myVector.push_back(value);
			}
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			std::cout << "Thrown from data entry\n";
			return 1;
		}
	}

	try {
		countSort(myVector);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cout << "Thrown from sort\n";
		return 1;
	}

	for (int i = 0; i < n; i++) {
		std::cout << myVector.at(i) << " ";
	}
}


