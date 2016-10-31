// Zadacha2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int n, sum = 0, currentNumber = 1;

	cout << "Input a number: ";
	cin >> n;

	cout << sum << "; ";

	for (int i = 0; i < n*n; i++) {
		sum += currentNumber;
		cout << sum << "; ";
		currentNumber *= 2;
	}

    return 0;
}

