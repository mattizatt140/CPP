// CS Module 6 GPA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int comparator(int audience[][2], int index1, int index2) 
{
	unsigned long long int ecode1, ecode2;
	ecode1 = audience[index1][0];
	ecode2 = audience[index2][0];

	for (int i = 1; i < audience[index1][1]; i++) {
		ecode1 *= audience[index1][0];
	}
	ecode1 %= 100;
	
	for (int i = 1; i < audience[index2][1]; i++) {
		ecode2 *= audience[index2][0];
	}
	ecode2 %= 100;
	
	if (ecode1 > ecode2) { return -1; }
	if (ecode1 == ecode2) { return 0; }
	if (ecode1 <= ecode2) { return 1; }
}

void sorting(int audience[][2], int N, int &i_index, int &j_index) //function can use comparison to determine lesser than greater than swapping
{
	for (int i = 0; i < N; i++) {
		int test = comparator(audience, i, i + 1);
		if (test == -1) {
			i_index = i;
			break;
		}
	}
	
	for (int j = N - 1; j > 0; j--) {
		int test = comparator(audience, j, j-1);
		if (test == 1) {
			j_index = j;
			break;
		}
	}
	int currMinIndex = i_index;
	for (i_index += 1; i_index < j_index; i_index++) {
		for (int i = i_index + 1; i < j_index; i++) {
			int test = comparator(audience, currMinIndex,i);
			if (test == -1) { currMinIndex = i; }
		}
		int temp[2][2];
		for (int j = 0; j < 2; j++) { 
			temp[0][j] = audience[i_index][j];
			audience[i_index][j] = audience[currMinIndex][j];
			audience[currMinIndex][j] = temp[0][j];
		}
	}
}

int main()
{
	int test;
	int audience[11][2] = { { 7,5 }, { 6,3 }, {11,2},{5,3},{2,7}, {5,3}, {9,4},{43,2}, {3,8}, {4,7}, {2,13}};
	int N = 11;
	int zero = 0;
	sorting(audience, N, zero, N);

	for (int i = 0; i < 11; i++) {
		cout << audience[i][0] << ", " << audience[i][1] << endl;
	}
	return 0;
}

