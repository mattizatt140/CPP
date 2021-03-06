// CS Module 5.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void getTotalGQ(int numOfStudents, int gq[], int sum_gq[]) {
	for (int i = 0; i < numOfStudents; i++) {
		int p = gq[i];
		sum_gq[p] += 1;
		}
}

void getTotalGPA(int numOfStudents, float gpa[], int sum_gpa[]) {

	for (int i = 0; i < numOfStudents; i++) {
		gpa[i] *= 10;
	}

	for (int i = 0; i < numOfStudents; i++) {
		int p = gpa[i]; 
		if (p == 0) { p = 0; }
		else if (p == 3 || p == 30) { p = 1; }
		else if (p == 6 || p == 60) { p = 2; }
		else if (p == 10 || p == 100) { p = 3; }
		sum_gpa[p] += 1;
	}

	for (int i = 0; i < 4; i++) {
		cout << sum_gpa[i] << endl;
	}
}

void getTotalCount(int numOfStudents, int gq[], float gpa[], int count[][5]) {
	
	for (int i = 0; i < numOfStudents; i++) {
		gpa[i] *= 10;
	}

	for (int i = 0; i < numOfStudents; i++) {
		for (int j = 0; j < numOfStudents; j++) {
			int q;
			int p = gq[i];
			int a = gpa[j];
			if (a == 0) { q = 0; }
			if (a == 3) { q = 1; }
			if (a == 6) { q = 2; }
			if (a == 10) { q = 3; }
			count[p][q] += 1;
		}
	}

	for (int i = 0; i < 12; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += count[i][j];
		}
		count[i][4] = sum;
	}

	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 12; j++) {
			sum += count[i][j];
		}
		count[12][i] = sum;
	}
}


int main()
{
	int numOfStudents{ 18 };
	int gq[6] = { 1,1,1,1,1,1 };
	int sum_gq[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
	
	float gpa[18] = { 0,1,0,1,0.3,0.6,0.6,0.6,1,1,1,0.3,0.6,0.6,0.6,0.3,1,0.3};
	int sum_gpa[18] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	
//	getTotalGQ(numOfStudents, gq, sum_gq);
	//cout << endl;
	getTotalGPA(numOfStudents, gpa, sum_gpa);
	return 0;
}

