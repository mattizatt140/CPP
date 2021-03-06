// Data Structures Gray Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

char xor_c(char a, char b) {
	return (a == b) ? '0' : '1';
}

char flip(char c) { 
	return (c == '0') ? '1' : '0'; 
}

string binarytoGray(string binary) {
	string Gray = "";

	Gray += binary[0];
	for (int i = 1; i < binary.length(); i++) {
		Gray += xor_c(binary[i - 1], binary[i]);
	}
	return Gray;
}

string graytoBinary(string gray) {
	string binary = "";

	binary += gray[0];
	for (int i = 1; i < gray.length(); i++)
	{
		if (gray[i] == '0')
			binary += binary[i - 1];
		 
		else
			binary += flip(binary[i - 1]);
	}

	return binary;
}

int main() {
	string binary = "0011";
	cout << binarytoGray(binary) << endl;
}