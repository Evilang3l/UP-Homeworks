// Zadacha1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void recursivePrint(int n, int currentN)
{
	for (int i = n; i >= currentN; i--) 
	{
		cout << i << " ";
	}

	if (currentN != 1)
	{
		int numOfSpaces = (2 * n - 1) - ((n - currentN) + 1) * 2;
		for (int i = 0; i < numOfSpaces; i++)
		{
			cout << "  ";
		}
	}

	for (int i = currentN; i <= n; i++)
	{
		if (i == 1)
		{
			continue;
		}

		if (i > 10 && currentN > 10 && i == currentN)
		{
			for (int k = 0; k < i - 10; k++)
			{
				cout << "  ";
			}
		}
		cout << i << " ";
	}

	cout << endl;
	if (currentN != 1) recursivePrint(n, currentN - 1);
	else return;
}

int main()
{
	int n;
	cin >> n;
	recursivePrint(n, n);
    return 0;
}

