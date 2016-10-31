// Zadacha2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int sum = 0;
unsigned readNumber() {
	unsigned n = 0;
	do
	{
		cout << "Please enter n: ";
		cin >> n;
	} while (n>500 || n<0);
	return n;
}
void fillArray(int arr[], int n) {
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
		sum = sum + arr[i];
	}
}
int main()
{
	unsigned int n = readNumber();
	int arr[n];
	fillArray(arr, n);
	if (sum>5000 || sum<0)
	{
		cout << "Sum must be below 5000.";
		return 0;
	}
	int currentElement = 0;
	int currentCount = 0;
	int count = 1;
	for (int i = 0; i<n; i++)
	{
		currentCount = 0;
		currentElement = arr[i];
		currentCount++;
		for (int j = i + 1; j<n; j++)
		{
			if (arr[j] == currentElement)
			{
				currentCount++;
				if (currentCount > count)
				{
					arr[0] = currentElement;
					count = currentCount;
				}
			}
		}
	}
	cout << "The most common element is " << arr[0];
	return 0;
}
