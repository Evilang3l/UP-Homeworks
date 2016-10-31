// Zadacha1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int main()
{
	int n, number = 0;

	do {
		cin >> n;
		if (n > 128) {
			cout << "Max value = 128, Min value = 0" << endl;
		}
	} while (n > 128);

	const int size = 128;
	int arr[size][size];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	int a = 0, b = 0;

	for (int i = 0; i < (2 * n - 1); i++) {
		if (i < n) {
			a = 0, b = i;
			do {
				arr[(n-1) - a][b] = number;
				number++;
				a++;
				b--;
			} while (a <= i);
		}
		else {
			a = i - (n - 1), b = (n - 1);
			do {
				arr[(n - 1) - a][b] = number;
				number++;
				a++, b--;
			} while (a < n);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
			if (arr[i][j + 1] < 9) {
				if (j == 0) cout << "   ";
				else cout << "  ";
			}else if(arr[i][j] == 9) cout << "  ";
			else cout << " ";
		}
		cout << endl;
	}

    return 0;
}

