#pragma once
#include <stack>

class textEditor {
private:
	std::stack<char> leftStack;
	std::stack<char> rightStack;
public:
	void insertWord(char word[]);
	void insertCharacter(char character);
	bool deleteCharacter();
	bool backSpaceCharacter();
	void moveCurser(int position);
	void moveLeft(int position);
	void moveRight(int position);
	void findAndReplaceChar(char findWhat, char replaceWith);
	void examineTop();
};