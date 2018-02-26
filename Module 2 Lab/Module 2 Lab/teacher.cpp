#include "stdafx.h"
#include "teacher.h"
#include <iostream>

teacher::teacher()
{}

teacher::teacher(std::string fName1, std::string lName1, int age1, std::string address1, std::string city1, std::string phone1)
{
	fName = fName1;
	lName = lName1;
	age = age1;
	address = address1;
	city = city1;
	phone = phone1;
}

teacher::~teacher()
{}

std::string teacher::_getFname()
{
	return this->fName;
}

std::string teacher::_getLname()
{
	return this->lName;
}

int teacher::_getAge()
{
	return this->age;
}

std::string teacher::_getAddress()
{
	return this->address;
}

std::string teacher::_getCity()
{
	return this->city;
}

std::string teacher::_getPhone()
{
	return this->phone;
}

void teacher::GradeStudent()
{
	std::cout << "Student graded" << std::endl;
}
void teacher::SitInClass()
{
	std::cout << "Sitting at front of class" << std::endl;
}