// CS Module 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int profitsEarned(int prices[]) {
	int day[5];
	int profit, max_profit;

	for (int i = 0; i < 5; i++) {
		day[i] = prices[i];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = i+1; j < 5; j++) {
			
			profit = prices[j] - day[i];
			if (i == 0 && j == 1) {
				max_profit = profit;
			}
				if (profit > max_profit) {
					max_profit = profit;
				}
		}
	}
	return max_profit;
}
int main()
{
	int aryPrices[5] = { 55718, 58718, 43713, 19420, 106852};
	int max_profit;
	max_profit = profitsEarned(aryPrices);
	cout << "Max Profit: $" << max_profit << endl;
}

