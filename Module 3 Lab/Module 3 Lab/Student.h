#pragma once
#include "Person.h"

class Student : public Person
{
	using Person::Person;

public:
	virtual ~Student();
	virtual void OutputIdentity();
	virtual void OutputAge();
};
