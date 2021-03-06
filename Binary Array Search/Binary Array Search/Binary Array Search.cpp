// Binary Array Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int binarySearch(int A[], int start, int end, int srchElement) {
	if (end == start + 1) {
		if (A[start] == srchElement) { return start; }
		else {
			return -1;
		}
	}
	int mid = (start + end) / 2;
	if (A[mid] == srchElement) {
		return mid;
	}
	else {
		if (A[mid] < srchElement) { return binarySearch(A, mid, end, srchElement); }
		else { return binarySearch(A, start, mid, srchElement); }
	}
}
int main()
{
	int n, A[100];
	std::cout << "Give size of array: "; std::cin >> n;
	if (n > 100 || n <= 0) { std::cerr << "Invalid" << std::endl; return -1; }

	std::cout << "Give values of array: " << std::endl;
	for (int i = 0; i < n; i++) { std::cout << i << ": "; std::cin >> A[i]; }

	int srchElement, index;
	do {
		std::cout << "Give element to search for (-1 to quit): "; std::cin >> srchElement;
		if (srchElement == -1) { break; }
		else {
			index = binarySearch(A, 0, n, srchElement);
			if (index == -1) { std::cout << srchElement << " not present!" << std::endl; }
			else { std::cout << srchElement << " present at index " << index << std::endl; }
		}
	} while (true);
	
}

