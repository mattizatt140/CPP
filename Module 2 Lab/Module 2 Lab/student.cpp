#include "stdafx.h"
#include "student.h"
#include <iostream>

student::student()
{}

student::student(std::string fName1, std::string lName1, int age1, std::string address1, std::string city1, std::string phone1)
{
	fName = fName1;
	lName = lName1;
	age = age1;
	address = address1;
	city = city1;
	phone = phone1;
}

student::~student()
{}

std::string student::_getFname()
{
	return this->fName;
}

std::string student::_getLname()
{
	return this->lName;
}

int student::_getAge()
{
	return this->age;
}

std::string student::_getAddress()
{
	return this->address;
}

std::string student::_getCity()
{
	return this->city;
}

std::string student::_getPhone()
{
	return this->phone;
}

void student::SitInClass()
{
	std::cout << "Sitting in main theater" << std::endl;
}