// OOP Module 7 GPA 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void royale(int n, int w, vector<int> &money, bool &flag) {
	flag = false;

	if (n == 2) {
		flag = true;
	}

	if (flag == false) {
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (money.at(i) == money.at(j) && (i != j)) {
					flag = true;
					break;
				}
			}
		}
	}

	if (flag == false) {
		for (int i = 1; i < n; i++) {
			if ((money.at(i)) == 3) {
				flag = true;
				break;
			}
		}
	}
}

