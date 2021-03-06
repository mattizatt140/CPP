// Algorithms Module 1 GPA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//sort num vector based off weight
//if weights are equal, sort based off num val

void sortImplement(vector<int> &num, vector<int> &weights, int start, int mid, int end) {
	int tempNum[100000];
	int tempWeight[100000];
	int i, j, index = start;

	for (i = start, j = mid + 1; (i <= mid) || (j <= end); ) {
		if (i <= mid && j <= end) {
			if (weights.at(j) > weights.at(i)) {
				tempWeight[index] = weights.at(j);
				tempNum[index] = num.at(j);
				j++;
			}
			else if (weights.at(j) == weights.at(i)) { //if weights are equal, evaluate num values
				if (num.at(j) > num.at(i)) {
					tempWeight[index] = weights.at(j);
					tempNum[index] = num.at(j);
					j++;
				}
				else {
					tempWeight[index] = weights.at(j);
					tempNum[index] = num.at(i);
					i++;
				}
			}
			else {
				tempWeight[index] = weights.at(i);
				tempNum[index] = num.at(i);
				i++;
			}
		}
		else {
			if (j <= end) {
				tempWeight[index] = weights.at(j);
				tempNum[index] = num.at(j);
				j++;
			}
			else {
				tempWeight[index] = weights.at(i);
				tempNum[index] = num.at(i);
				i++;
			}
		}
		index++;
	}
	for (int k = start; k <= end; k++) {
		weights.at(k) = tempWeight[k];
		num.at(k) = tempNum[k];
	}
}

void customSort(vector<int> & num, vector<int> & weights, int start, int end) {
	if (end == start) {
		return;
	}
	int mid = ((start + end) / 2);
	customSort(num, weights, start, mid);
	customSort(num, weights, mid + 1, end);
	sortImplement(num, weights, start, mid, end);
}
int main()
{
	vector<int> num = { 7,1,1,8,2,5,8,2 };
	vector<int> weights = { 1,1,7,8,2,9,9,9 };
	customSort(num, weights, 0, num.size() - 1);
	for (int i = 0; i < num.size(); i++) {
		cout << num.at(i) << " ";
	}
    return 0;
}