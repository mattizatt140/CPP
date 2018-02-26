#pragma once
#include <string>

class Person
{
private:
	int age;
	std::string first_name;
	std::string last_name;
	std::string race;
protected:
	std::string phone;
public:
	Person();
	Person(std::string fName, std::string lName, int age, std::string race, std::string phone);
	virtual ~Person();

	int get_age();
	std::string get_fName();
	std::string get_lName();
	std::string get_race();

	virtual void OutputIdentity() = 0;
	virtual void OutputAge();

};