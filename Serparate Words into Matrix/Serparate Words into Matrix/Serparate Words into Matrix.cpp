// Serparate Words into Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	char sentence[200], words[50][50];
	int i, char_count = 0, length, numwords = 0;
	
	cout << "Enter a sentence: " << endl;
	gets_s(sentence);

	for (i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == ' ') continue;
		if (sentence[i] != ' ') {
			words[numwords][char_count] = sentence[i];
			char_count++;
			if (sentence[i + 1] == ' ' || sentence[i + 1] == '\0') {
				words[numwords][char_count] = '\0';
				numwords++;
				char_count = 0;
			}
		}
	}

	for (i = 0; i < numwords; i++) {
		cout << words[i];
	}
}