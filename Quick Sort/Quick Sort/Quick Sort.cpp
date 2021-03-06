// Quick Sort.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "QuickSort.h"
#include <thread>

template <typename T> std::ostream &operator<<(std::ostream &os, std::vector<T> &vec);

int main() {
	std::exception except; std::string input;
	try {
		QuickSort<int> *obj = new QuickSort<int>; int input;

		obj->setVecRandom();
		obj->classVec.shrink_to_fit();
		std::cout << std::endl << "Starting Quick Sort" << std::endl;
		
		if (obj->getVecSize() < 40000) {
			obj->quickSort(obj->classVec, obj->getLow(), obj->getHigh());
		}

		if (obj->getVecSize() >= 40000) {
			std::thread waitThread = obj->waitThread();

			obj->quickSort(obj->classVec, obj->getLow(), obj->getHigh());
			obj->classVec.shrink_to_fit();
			
			obj->switchFlag();
			waitThread.join();
		}
		std::cout << "Quick Sort Complete\n" << std::endl;
		std::cout << "Press 1 to View Sorted Vector\n";
		std::cout << "Press Any Other Key to Quit\n"; std::cin >> input;
		
		if (input == 1) {
			std::cout << obj->classVec << std::endl;
			system("PAUSE");
		}
	}
	catch (std::exception &e) {
		system("CLS");
		std::cout << "ERROR: INVALID INPUT\nPRESS '1' TO TRY AGAIN" << std::endl;
	}
}

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		if (i == 35) { os << std::endl; }

		if (i == (vec.size() - 1)) {
			os << vec.at(i) << "]" << std::endl;
			break;
		}
		if (i == 0) {
			os << "[";
		}
		os << vec.at(i) << ", ";
	}
	return os;
}