#pragma once
#include <string>

class teacher
{
private:
	std::string fName;
	std::string lName;
	int age;
	std::string address;
	std::string city;
	std::string phone;
public:
	teacher();
	teacher(std::string fName1, std::string lName1, int age1, std::string address1, std::string city1, std::string phone1);
	~teacher();

	std::string _getFname();
	std::string _getLname();
	int _getAge();
	std::string _getAddress();
	std::string _getCity();
	std::string _getPhone();

	void GradeStudent();
	void SitInClass();
};