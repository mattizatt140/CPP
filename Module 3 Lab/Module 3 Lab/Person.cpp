#include "stdafx.h"
#include "Person.h"
#include <string>
#include <iostream>

Person::Person() {}

Person::Person(std::string fName, std::string lName, int age1, std::string race1, std::string _phone)
{
	first_name{ fName }, last_name{ lName }, age{ age1 }, race{ race1 }, phone{ _phone }
}
	
Person::~Person() {}

Person::get_age()
{
	return age;
}

Person::get_fName()
{
	return first_name;
}

Person::get_lName()
{
	return last_name;
}

Person::get_race()
{
	return race;
}

void Person::OutputAge()
{
	std::cout << "I am " << this->get_age() << "years old" << std::endl;
}