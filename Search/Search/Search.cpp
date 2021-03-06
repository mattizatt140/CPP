// Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>

void vecNumGen(std::vector<int> &passVec, int vecSize) {
	try {
		srand((unsigned)time(0));

		for (int i = 0; i < vecSize; i++) {
			int random_num = rand() % 100 + 1;
			passVec.push_back(random_num);
		}
	}
	catch (std::exception &e) {
		throw;
	}
}

void searchVector(std::vector<int> &refVec, int searchNum) {
	try {
		int index;
		for (int i = 0; i < refVec.size(); i++) {
			if (refVec[i] == searchNum) {
				index = i;
				std::cout << "Number located at index " << i << " of vector" << std::endl;
				break;
			}
			if (i == (refVec.size() - 1) && (refVec[i] != searchNum)) {
				std::cout << "Not found" << std::endl;
			}
		}
	}
	catch (std::exception &e) {
		throw;
	}
}

int main()
{
	try {
		std::vector<int> myVector;
		int index, searchNum;
		float vecSize;

		std::cout << "Vector size: "; std::cin >> vecSize;

		while (std::cin.fail() || (floor(vecSize) != ceil(vecSize))) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Vector size: "; std::cin >> vecSize;
		}
			
		vecNumGen(myVector, vecSize);
			
		std::cout << "[ ";
		for (int i = 0; i < myVector.size(); i++) {
			if (i == (myVector.size() - 1)) {
				std::cout << myVector[i] << " ]" << std::endl;
				break;
			}
			std::cout << myVector[i] << ", ";
		}

		std::cout << "Search number: "; std::cin >> searchNum;
		searchVector(myVector, searchNum);
	}
	catch (std::bad_alloc) {
		std::cout << "Bad allocation" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

