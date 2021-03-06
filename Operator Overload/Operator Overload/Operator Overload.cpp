// Operator Overload.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Var {
public:
	double x;
	double y;
	static int z;

	Var() { z++; }
	Var(double _x, double _y) {
		x = _x; y = _y;
		z++;
	}
	~Var() {
		std::cout << "Destructor Called" << std::endl;
		z--;
	}
	Var *operator+(double factor) {
		this->x = x + factor;
		this->y = y + factor;
		return this;
	}
	Var operator=(Var *copy) {
		this->x = copy->x;
		this->y = copy->y;
		delete copy;
		return *this;
	}
//	std::ostream &operator<<(std::ostream &stream, const Var &bj);
};

std::ostream &operator<<(std::ostream &stream, const Var &obj) {
	stream << "(" << obj.x << ", ";
	stream << obj.y << ")" << std::endl;
	return stream;
}
std::istream &operator>>(std::istream &is, Var &obj) {
	std::cout << "Input x: "; std::cin >> obj.x;
	std::cout << "Input y: "; std::cin >> obj.y;
	return is;
}

int Var::z;

int main()
{
	Var test;
	std::cin >> test;
	std::cout << "Test: " << test << std::endl;
	Var test1(2, 4);
	test = test1;
	std::cout << "Test1: " << "(" << test.x << ", " << test.y << ") " << std::endl;
	std::cout << "Before: " << "(" << test1.x << ", " << test1.y << ") " << std::endl;
	test1 + 6;
	std::cout << "After: " << "(" << test1.x << ", " << test1.y << ") " << std::endl;
	Var test2;
	std::cout << Var::z << std::endl;
	std::cout << test1 << std::endl;
}