// Simple Try-Catch rollback.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <exception>
#include <iostream>
using namespace std;

void updateVector(std::vector<std::string>& firstvector_, std::vector<std::string>& secondvector_, std::string newString) {
	firstvector_.push_back(newString);
	try {
		secondvector_.push_back(newString);
	}
	catch (...) {
		firstvector_.pop_back();
		cout << "second vector update failed." << endl;
	}
}

void updateVector2(std::vector<std::string>& firstvector_, std::vector<std::string>& secondvector_, std::string newString) {
	firstvector_.push_back(newString);
	try {
		std::bad_alloc excep;
		throw excep;
		secondvector_.push_back(newString);
	}
	catch (...) {
		firstvector_.pop_back();
		cout << "second vector update failed." << endl;
	}
}

int main() {
	std::vector<std::string> firstvector;
	std::vector<std::string> secondvector;
	std::string mystring("Hello world!");

	cout << "Calling updateVector " << endl;

	updateVector(firstvector, secondvector, mystring);

	cout << "first vector size is " << firstvector.size() << " second vector size is " << secondvector.size() << endl;

	cout << "Calling updateVector2 " << endl;

	updateVector2(firstvector, secondvector, mystring);

	cout << "first vector size is " << firstvector.size() << " second vector size is " << secondvector.size() << endl;
}