#pragma once
#include "student.h"
#include "teacher.h"
#include <string>

class course
{
private:
	std::string name;

public:
	course(std::string name1)
	{
		name = name1;
	}

	std::string getName()
	{
		return name;
	}

	student studentClass[3];
	teacher oneTeacher;

	void reClass0(student newStudent)
	{
		studentClass[0] = newStudent;
	}

	void reClass1(student newStudent)
	{
		studentClass[1] = newStudent;
	}

	void reClass2(student newStudent)
	{
		studentClass[2] = newStudent;
	}

	void reTeach(teacher &newTeacher)
	{
		oneTeacher = newTeacher;
	}
};
