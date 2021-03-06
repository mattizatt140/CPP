// OOP Module 7 GPA 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SafeMap.h"
#include<iostream>
#include<list>
using namespace std;

int main() {
	SafeMap obj(6);
	
	obj.addSafeRoute(2, 1);
	obj.addSafeRoute(4, 3);
	obj.addSafeRoute(1, 0);
	obj.addSafeRoute(1, 3);
	obj.addSafeRoute(4, 5);
	obj.addSafeRoute(3, 2);
	obj.addSafeRoute(1, 4);
	try {
		obj.isReachable(2, 5);
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
}