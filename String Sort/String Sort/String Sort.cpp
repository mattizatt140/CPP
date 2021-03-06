// String Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

void mergesort(std::vector<std::string> &refVec, int start, int end);
void mergeSortedSubarrays(std::vector<std::string> &refVec, int start, int mid, int end);
bool lexEarlier(std::string str_2, std::string str_1);

int main() {
	int n;
	std::vector<std::string> strVec;

	std::cout << "Give number of strings: ";
	std::cin >> n; 
	if ((n <= 0)) {
		std::cout << "Invalid value of n: " << n << std::endl;
		return 1;
	}
	else if ((n == 1)) { 
		std::cout << "What's the point?" << std::endl;
		return 0;
	}
	std::cout << "Give " << n << " strings (seperated by newlines):" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string nextStr;

	for (int i = 0; i < n; i++) {
		std::cout << "String " << i + 1 << ": "; 
		getline(std::cin, nextStr);
		strVec.push_back(nextStr);
	}

	std::cout << "++++++++++++++++" << std::endl;
	std::cout << "Unsorted array: " << std::endl;
	std::cout << "++++++++++++++++" << std::endl;

	for (int i = 0; i < n; i++) {
		std::cout << strVec[i] << std::endl;
	}

	mergesort(strVec, 0, n);
	
	std::cout << std::endl;
	std::cout << "++++++++++++++++" << std::endl;
	std::cout << "Sorted array: " << std::endl;
	std::cout << "++++++++++++++++" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << strVec[i] << std::endl;
	}
}

void mergesort(std::vector<std::string> &refVec, int start, int end) {
	if (end == start + 1) { return; }
	int mid = (start + end) / 2;
	mergesort(refVec, start, mid);
	mergesort(refVec, mid, end);
	mergeSortedSubarrays(refVec, start, mid, end);
}

void mergeSortedSubarrays(std::vector<std::string> &refVec, int start, int mid, int end) {
	int i, j, index = start;
	std::vector<std::string> tempVec(refVec.size());

	for (i = start, j = mid; ((i < mid) || (j < end)); index++) {
		if ((i < mid) && (j < end)) {
			if (lexEarlier(refVec[j], refVec[i])) { tempVec[index].assign(refVec[j++]); }
			else { tempVec[index].assign(refVec[i++]); }
		}

		else {
			if (i < mid) { tempVec[index].assign(refVec[i++]); }
			else { tempVec[index].assign(refVec[j++]); }
		}
	}
	
	for (int i = start; i < end; i++) {
		refVec[i].assign(tempVec[i]);
	}
}

bool lexEarlier(std::string str_1, std::string str_2)
{
	if ((str_1.compare(str_2) < 0)) {
		return true;
	}
	else {
		return false;
	}
}