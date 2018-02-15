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

	string name1;
	int age1;
	int height1;
	int weight1;

	string _getName() { return name; }
	int _getAge() { return height; }
	int _getHeight() { return height; }
	int _getWeight() { return weight; }
};

int main()
{
	Person *pPerson = new Person("Jeff", 26, 68, 140);
	cout << "This is " << pPerson->_getName();
	cout << ": he weighs " << pPerson->_getWeight() << " pounds, is " << pPerson->_getAge() << " years old, and is " << pPerson->_getHeight() << " inches tall" << endl;
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
	cout << "pDouble value: " << *pDouble << endl;

	delete pDouble;

}
//cout << pDouble << endl; //crashes code
/*
Person test("Jeff", 26, 65, 150);
cout << test._getName << " " << test._getAge << " " << test._getHeight << " " << test._getWeight << endl;

ModifyPerson(test);
cout << test._getName << " " << test._getAge << " " << test._getHeight << " " << test._getWeight << endl;
}
*/


