// Radix Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void radixSort(int a[], int n, int b, int k) {

	for (int p = 1; p < k; p *= b) {
		int *count = new int[b];
		for (int i = 0; i < b; i++) {
			count[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			count[(a[i] / p) % b]++;
		}
		for (int i = 1; i < b; i++) {
			count[i] += count[i - 1];
		}
		
		int *newarr = new int[n];

		for (int i = n - 1; i >= 0; i--) {
			newarr[count[(a[i] / p) % b] - 1] = a[i];
		}
		for (int i = 0; i < n; i++) {
			a[i] = newarr[i];
		}
	}
}

int main() {
	
	int n;
	std::cin >> n; int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	radixSort(a, n, n, n*n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
    return 0;
}

