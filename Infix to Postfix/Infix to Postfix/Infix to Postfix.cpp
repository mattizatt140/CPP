// Infix to Postfix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

bool checkParentheses(char infix[]) {
	int open = 0, close = 0, i = 0;
	while (infix[i] != '\0') {
		if (infix[i] == '(') {
			open++;
		}
		if (infix[i] == ')') {
			close++;

			if (close > open) {
				return false;
			}
		}
		i++;
	}
	if (open == close) {
		return true;
	}
	else {
		return false;
	}
}

bool isValid(char currentChar) {
	return ((currentChar >= 65 && currentChar <= 90) ||
		(currentChar >= 97 && currentChar <= 122) ||
		(currentChar >= 40 && currentChar <= 43) ||
		currentChar == 45 ||
		currentChar == 47 ||
		currentChar == 94);
}

bool validate(char infix[]) {
	int i = 0;
	while (infix[i] != '\0') {
		if (!isValid(infix[i])) {
			return false;
		}
		else {
			i++;
		}
	}
	
	if (checkParentheses(infix = false)) {
		return false;
	}

	return true;
}

int priorityNumber(char Operator) {
	if (Operator == '^') {
		return 0;
	}
	if (Operator == '*' || Operator == '/') {
		return 1;
	}
	if (Operator == '+' || Operator == '-') {
		return 2;
	}
	if (Operator == '(') {
		return 3;
	}
}

bool checkPriority(char currentOperator, char topOperator) {
	if (priorityNumber(currentOperator) < priorityNumber(topOperator)) {
		return true;
	}
	else {
		return false;
	}
}

bool isOperand(char currentChar) {
	return ((currentChar >= 65 && currentChar <= 90) ||
			(currentChar >= 97 && currentChar <= 122));
}

void infix2Postfix(char infix[], char answer[]) {
	int i = 0, j = 0; char currentChar;
	char postfix[50] = "";
	std::stack<char> operatorStack;
	
	while (infix[i] != '\0') {
		currentChar = infix[i];
		if (isOperand(currentChar)) {
			postfix[j] = currentChar;
			j++;
		}
		else {
			if (currentChar == '(') {
				operatorStack.push(currentChar);
				i++;
				continue;
			}
			else if (operatorStack.empty() && currentChar != ')') {
				operatorStack.push(currentChar);
			}
			else {
				if (checkPriority(currentChar, operatorStack.top())) {
					operatorStack.push(currentChar);
				}
				else {
					while (!operatorStack.empty()) {
						if (operatorStack.top() == '(') {
							operatorStack.pop();
							break;
						}
						postfix[j] = operatorStack.top();
						j++;
						operatorStack.pop();
					}
					if (currentChar != ')') {
						operatorStack.push(currentChar);
					}
				}
			}
		}
		i++;
		}
	while (!operatorStack.empty()) {
		postfix[j] = operatorStack.top();
		operatorStack.pop();
		j++;
	}
	strcpy_s(answer, 50, postfix);
}

int main()
{
	char infix[50]; char postfix[50];
	std::cout << "Input infix equation: "; std::cin >> infix;
	std::cout << "Infix: " << infix << std::endl;
	infix2Postfix(infix, postfix);
	std::cout << "Postfix: " << postfix << std::endl;
	return 0;
}