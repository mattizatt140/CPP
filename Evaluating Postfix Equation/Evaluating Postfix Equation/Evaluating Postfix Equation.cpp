// Evaluating Postfix Equation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <string>

bool isOperator(char currentChar) {
	if (currentChar == '+' || currentChar == '-' ||
		currentChar == '*' || currentChar == '/' ||
		currentChar == '^') {
		return true;
	}
	else {
		return false;
	}
}

void getValues(std::string postfix, float value[]) {
	int i = 0;
	char currentChar;
	while (postfix[i] != '\0') {
		currentChar = postfix[i];
		if (!isOperator(currentChar)) {
			std::cout << "Enter value of " << currentChar << ": ";
			std::cin >> value[currentChar];
		}
		i++;
	}
}

float calculateValues(float operand1, float operand2, char Operator) {
	if (Operator == '+') {
		return operand1 + operand2;
	}
	if (Operator == '-') {
		return operand1 - operand2;
	}
	if (Operator == '*') {
		return operand1 * operand2;
	}
	if (Operator == '/') {
		return operand1 / operand2;
	}
	if (Operator == '^') {
		return pow(operand1, operand2);
	}
}

float evaluatePostfix(std::string postfix) {
	std::stack<float> Stack;
	char currentChar;
	int i = 0;
	float result, operand1, operand2, value[256];
	getValues(postfix, value);
	while (postfix[i] != '\0') {
		currentChar = postfix[i];
		if (isOperator(currentChar)) {
			operand2 = Stack.top();
			Stack.pop();
			operand1 = Stack.top();
			Stack.pop();
			result = calculateValues(operand1, operand2, currentChar);
			Stack.push(result);
		}
		else {
			Stack.push(value[currentChar]);
		}
		i++;
	}
	return Stack.top();
}

int main()
{
	std::string postfix;
	std::cout << "Enter postfix equation: "; std::cin >> postfix;
	float var = evaluatePostfix(postfix);
	std::cout << "Solution: " << var << std::endl;
}

