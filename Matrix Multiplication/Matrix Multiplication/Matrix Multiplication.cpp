// Matrix Multiplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, j, k, rowA, colA, colB;
	double MatA[100][100], MatB[100][100], MatC[100][100];
	
	cout << "Enter size of Matrix A: \n";
	cout << "Rows: ";
	cin >> rowA;
	cout << "Columns: ";
	cin >> colA;
	cout << "\nEnter values: " << endl;

	for (i = 0; i < rowA; i++) {
		for (j = 0; j < colA; j++) {
			cout << i << ", " << j << ": ";
			cin >> MatA[i][j];
		}
	}

	cout << "\nEnter size of Matrix B: \n";
	cout << "Rows: " << colA << endl;
	cout << "Columns: ";
	cin >> colB; 
	cout << "\nEnter values: " << endl;

	for (i = 0; i < colA; i++) {
		for (j = 0; j < colB; j++) {
			cout << i << ", " << j << ": ";
			cin >> MatB[i][j];
		}
	}

	cout << "\nMatrix C: \n";
	cout << "Rows: " << rowA << endl;
	cout << "Columns: " << colB << endl;
	cout << "\nValues: " << endl;

	for (i = 0; i < rowA; i++) {
		for (j = 0; j < colB; j++) {
			MatC[i][j] = 0;
			for (k = 0; k < colA; k++){
				MatC[i][j] = MatC[i][j] + (MatA[i][k] * MatB[k][j]);
			}
		}
	}

	for (i = 0; i < rowA; i++) {
		for (j = 0; j < colB; j++) {
			cout << setprecision(5);
			cout << i << ", " << j << ": " << fixed << MatC[i][j] << endl;
		}
	}
	return 0;
}

