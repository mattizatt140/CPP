// Letters and Words in String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	string test;
	int i, j = 0, letters, words = 1;
	getline(cin, test);

	for (i = 0;; i++) {
		test[i];
		if (test[i] == '\0') {
			break;
		}
		if (((test[i] > 64) && (test[i] < 91)) || ((test[i] > 96) && (test[i] < 123))) {
			j++;
		}
	}
	letters = j;
	
	for (j = 0;; j++) {
		if (test[j] == ' ') {
			words++;
		}
		if (test[j] == '\0') {
			break;
		}
	}
	
	cout << "'" << test << "' has ";
	cout << letters << " letters and " << words << " words" << endl;
}

