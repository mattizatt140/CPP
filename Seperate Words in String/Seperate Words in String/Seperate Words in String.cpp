// Seperate Words in String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	char nameStrng[50], firstName[50], lastName[50];
	int nChar, lengthf, lengthl, i, j;
	gets_s(nameStrng); nChar = strlen(nameStrng);
	i = 0;

	for (j = 0; j < nChar; j++, i++) {
		if (nameStrng[i] != ' ') {
			firstName[j] = nameStrng[i];
		}
		else break;
	}
	lengthf = j;
	firstName[lengthf] = '\0';
	
	while (nameStrng[i] == ' ') i++;
	if (i == nChar) {
		cout << "Given string contains one name" << endl;
		return -1;
	}

	for (j = 0; j < nChar; j++, i++) {
		if (nameStrng[i] != ' ') {
			lastName[j] = nameStrng[i];
		}
		else break;
	}
	lengthl = j;
	lastName[lengthl] = '\0';
}

