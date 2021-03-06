// Text Editor App.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "textEditor.h"
#include <iostream>

int main()
{
	int i = 0; char text[80]; textEditor txt;

	std::cout << "Enter the word to be inserted: ";
	std::cin.getline(text, 80);
	txt.insertWord(text);
	std::cout << "Inserting the word:       ";
	txt.examineTop();

	std::cout << "Enter the word to be inserted: ";
	std::cin.getline(text, 80);
	txt.insertWord(text);
	std::cout << "Inserting the word:       ";
	txt.examineTop();

	std::cout << "Move cursor to the position 14: ";
	txt.moveCurser(14);
	txt.examineTop();

	std::cout << "Move cursor to the position 17: ";
	txt.moveCurser(17);
	txt.examineTop();

	for (i = 0; i < 3; i++) {
		if (!txt.deleteCharacter()) {
			std::cout << "There is nothing to delete. ";
			std::cout << "Move your cursor accordingly to ";
			std::cout << "delete the character ";
		}
		else {
			std::cout << "Delete characters using DEL: ";
			txt.examineTop();
		}
	}

	for (i = 0; i < 7; i++) {
		if (!txt.backSpaceCharacter()) {
			std::cout << "There is nothing to delete. ";
			std::cout << "Move your cursor accordingly to ";
			std::cout << "delete the character ";
		}
		else {
			std::cout << "Delete characters using Backspace: ";
			txt.examineTop();
		}
	}

	txt.findAndReplaceChar('t', 'T');
	std::cout << "Replace occurances of t with T: ";
	txt.examineTop();
	return 0;
}