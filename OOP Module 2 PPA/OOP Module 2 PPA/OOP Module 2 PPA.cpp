// OOP Module 2 PPA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct student {
	string name;
	int age;
	float marks;
};

student *initiateStudent(string name, int age, float marks) {
	student *ptr = new student;
	ptr->name = name;
	ptr->age = age;
	ptr->marks = marks;
	return ptr;
}

student *highestScorer(student **stud, int totalStudents) {
	student *topper = new student;
	for (int i = 0; i < totalStudents; i++) {
		if (stud[i]->marks > topper->marks) {
			topper = stud[i];
		}
	}
	return topper;
}
int main()
{
	string name;
	int age;
	float marks;

	student *student1;
	cin >> name >> age >> marks;
	student1 = initiateStudent(name, age, marks);
	cout << student1->name << endl;
}

