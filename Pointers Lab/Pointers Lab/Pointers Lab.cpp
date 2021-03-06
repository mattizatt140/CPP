#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string name;
	int age;
	int height;
	int weight;

public:
	Person()
	{}
	Person(string name1)
		:name{ name1 }
	{}
	Person(string name1, int age1)
		:name{ name1 }, age{ age1 }
	{}
	Person(string name1, int age1, int height1)
		:name{ name1 }, age{ age1 }, height{ height1 }
	{}
	Person(string name1, int age1, int height1, int weight1)
		:name{ name1 }, age{ age1 }, height{ height1 }, weight{ weight1 }
	{}
	~Person()
	{}

	void _newName( string name2 ) { name = name2; }
	void _newAge( int age2 ) { age = age2; }
	void _newHeight( int height2 ) { height = height2; }
	void _newWeight( int weight2 ) { weight = weight2; }

	string _getName() { return name;}
	int _getAge() { return age;}
	int _getHeight() { return height;}
	int _getWeight() { return weight;}
};

int main()
{
	Person *pPerson = new Person("Jimmy", 17, 68, 150);

	cout << "This is " << pPerson->_getName();
	cout << ": he weighs " << pPerson->_getWeight() << " pounds, is " << pPerson->_getAge();
	cout << " years old, and is " << pPerson->_getHeight() << " inches tall" << endl;
	pPerson->_newName("Jim");
	cout << "I prefer calling him " << pPerson->_getName() << ", though" << endl;
	cout << "The memory address of the Jimmy object is " << pPerson << endl;
	delete pPerson;
	
	pPerson = new Person("Jess", 17);
	cout << pPerson->_getName() << ", Jimmy's friend, is " << pPerson->_getAge() << " years old, too" << endl;
	cout << "The memory address of the Jess object is " << pPerson << endl;
	delete pPerson;
}

/*
void PassByValue(int numVal)
{
	numVal++;
	cout << "In PassByValue()" << endl;
	cout << "Value is " << numVal << endl;
}


void PassByRef(int &numVal)
{
	numVal = 50;
	cout << "In PassByRef()" << endl;
	cout << "Value is " << numVal << endl;
}

void ModifyPerson(Person &_class)
{
	_class.name1 = "Tom";
}


int main()
{
	
	int num1 = 3;
	int num2;
	int *pNum = &num2;
	*pNum = 5;

	PassByValue(num1);
	cout << "In main()" << endl;
	cout << "Value is " << num1 << endl;

	PassByRef(*pNum);
	cout << "In main()" << endl;
	cout << "Value is " << *pNum << endl;

	PassByValue(*pNum);
	

	double *pDouble = new double;
	*pDouble = 2.0;
	std::cout << "pDouble value: " << *pDouble << endl;

	delete pDouble;
	std::cout << pDouble << endl;
}
*/




