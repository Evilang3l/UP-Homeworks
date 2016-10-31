// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"

using namespace std;
int mistery(int x)
{
	if (x == 0) return 0;
	if (x % 2) return 1 + mistery(x - 1);
	return 2 * mistery(x / 2);
}


int main()
{
	cout << mistery(17);
	return 0;
}

