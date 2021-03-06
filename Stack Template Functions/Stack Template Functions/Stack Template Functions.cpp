// Stack Template Functions.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <deque>
using namespace std;
#define MAX_SIZE 3;

template <typename T> T bottom(stack<T> myStack) {

	stack<T> myStack_Copy = myStack;

	while (!myStack.empty()) {
		myStack.pop();
		if (myStack.empty()) {
			break;
		}
		myStack_Copy.pop();
	}
	return myStack_Copy.top();
}

template <typename T> void displayStack(stack<T> myStack) {
	
	stack<T> myStack_Reverse;

	while (!myStack.empty()) {
		T element = myStack.top();
		myStack.pop();
		myStack_Reverse.push(element);
	}

	while (!myStack_Reversej.empty()) {
		T element = myStack_Reverse.top();
		myStack_Reverse.pop();
		cout << element << " ";
	}
};

struct Node {
	char info;
	Node *next;
};

struct Stack {
	Node *top;
};
typedef struct Stack Stack;

bool g(string y) {
	bool ans = false;
	queue <char> Q; // empty queue
	stack <char> S; // empty stack

	for (int i = 0; i < y.size(); i++) {
		Q.push(y[i]);
		S.push(y[i]);
	}

	while (!S.empty()) {
		if (Q.front() != S.top()) {
			ans = true;
			break;
		}
		else {
			Q.pop();
			S.pop();
		}
	}

	return ans;
}

void function1(int n, queue<int> q) {
	q.push(0);
	q.push(1);
	for (int i = 0; i < n; i++) {
		int a = q.pop();
		int b = q.pop();
		q.push(b);
		q.push(a + b);
		cout << a << endl;
	}
}

int main() {
	queue<int> q; //creates an empty queue
	function1(53, q);
}


