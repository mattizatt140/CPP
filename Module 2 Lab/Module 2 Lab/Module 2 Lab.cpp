#include "stdafx.h"
#include "course.h"
#include "student.h"
#include "teacher.h"
#include <iostream>

int main()
{
	student student1("Jerry", "Smith", 21, "23 Cobble Ave", "New York City", "4323452096");
	student student2("Stacy", "Smith", 23, "16 James St", "Chicago", "3448923040");
	student student3("Smoothie", "Jones", 153, "Witchita Cir", "Texas", "6546546545");
	teacher teacher1("Jen", "Jones", 35, "Whatever 23 St", "Chicago", "5643456547");

	course *pCourse = new course("Intermediate C++");
	
	pCourse->reClass0(student1);
	pCourse->reClass1(student2);
	pCourse->reClass2(student3);
	pCourse->reTeach(teacher1);

	std::cout << pCourse->getName() << std::endl;
	
}

