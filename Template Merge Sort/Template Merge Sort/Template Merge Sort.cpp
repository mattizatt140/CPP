// Template Merge Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

template <typename T>
void mergeSort(std::vector<T> &refVec, int start, int end) {
	if (end == start + 1) { return; }
	int mid = (start + end) / 2;
	mergeSort(refVec, start, mid);
	mergeSort(refVec, mid, end);
	mergeSorted(refVec, start, mid, end);
}

template <typename T>
void mergeSorted(std::vector<T> &refVec, int start, int mid, int end) {
	int i, j;
	std::vector<T> tempVec(refVec.size());
	int index = start;

	for (i = start, j = mid; ((i < mid) || (j < end));) { //reassigns organized vectors up to one half
		if ((i < mid) && (j < end)) {
			if (refVec[j] < refVec[i]) {
				tempVec.insert(tempVec.begin() + index, refVec[j]);
				j++;
			}
			else {
				tempVec.insert(tempVec.begin() + index, refVec[i]);
				i++;
			}
		}
		else {
			if (i < mid) { //assigns uncompleted half to tempVec
				tempVec.insert(tempVec.begin() + index, refVec[i]);
				i++;
			}
			else {
				tempVec.insert(tempVec.begin() + index, refVec[j]);
				j++;
			}
		}
		index++;
	}
	for (i = start; i < end; i++) {
		refVec[i] = tempVec[i]; //reassigns organized values to original vector
	}
	return;
}

int main()
{
	int input, N;
	srand((unsigned)time(0));
	
	std::cout << "Give integer count: ";
	std::cin >> input; std::vector<int> myVec(input);

	std::cout << "Unsorted: ";
	for (int i = 0; i < myVec.size(); i++) { //user defines the amount of numbers generated into vector
		
		int random_integer = rand() % 1000 + 1; //generates random integers up to 1000
		myVec.at(i) = random_integer;

		if (i == (myVec.size() - 1)) {
			std::cout << myVec.at(i) << std::endl;
			break;
		}
		if (i % 32 == 0) {
			std::cout << std::endl;
		}
		std::cout << myVec.at(i) << ", ";
	}
	
	mergeSort(myVec, 0, myVec.size());
	
	std::vector<int>::iterator it;

	std::cout << std::endl << "Sorted: ";
	for (int i = 0; i < myVec.size(); i++) {
		if (i == (myVec.size() - 1)) {
			std::cout << myVec.at(i) << std::endl;
			break;
		}
		if (i % 32 == 0) {
			std::cout << std::endl;
		}
		std::cout << myVec.at(i) << ", ";
	}
}

