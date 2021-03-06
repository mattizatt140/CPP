// Selective Sort With Vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <exception>
#include <ctime>

int selectSort(std::vector<int> &passVec, int index, int end) {
	try {
		int minIndex = index;
		for (index; index < end; index++) {
			if (passVec[index] <= passVec[minIndex]) {
				minIndex = index;
			}
		}
		return minIndex;
	}
	catch (std::exception &e) {
		throw;
	}
}

void swap(std::vector<int> &passVec, int index, int minIndex) {
	try {
		int temp = passVec[index];
		passVec[index] = passVec[minIndex];
		passVec[minIndex] = temp;
	}
	catch (std::exception &e) {
		throw;
	}
}

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

void selectCall(std::vector<int> &passVec, int vecSize) {
	try {
		for (int i = 0; i < passVec.size(); i++) {
			int minIndex = selectSort(passVec, i, vecSize);
			swap(passVec, i, minIndex);
		}
	}
	catch (std::exception &e) {
		throw;
	}
}

void displayVec(std::vector<int> &passVec) {
	try {
		std::cout << "[ ";
		for (int i = 0; i < passVec.size(); i++) {
			if (i == (passVec.size() - 1)) {
				std::cout << passVec[i] << " ]" << std::endl;
				break;
			}
			std::cout << passVec[i] << ", ";
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
		int vecSize;

		std::cout << "Input size of vector: "; std::cin >> vecSize;

		vecNumGen(myVector, vecSize);
		displayVec(myVector);

		selectCall(myVector, vecSize);
		displayVec(myVector);
		return 0;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
}