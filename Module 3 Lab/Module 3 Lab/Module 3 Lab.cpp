#include "stdafx.h"
#include "Person.h"
#include "Teacher.h"
#include "Student.h"
#include <iostream>
#include <string>

int main()
{
	Student student1("Jim", "John", 17, "White", "6308152543");
	std::cout << student1.OutputIdentity << std::endl;
	return 0;
}

