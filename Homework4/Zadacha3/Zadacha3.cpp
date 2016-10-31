// Zadacha3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void reverseWords(char* str) {
	int prevDiv = 0;
	char *tmp;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			tmp = new (nothrow) char[i + 1];
			for (int k = 0; k < i; k++) {
				tmp[k] = str[prevDiv + k];
			}
			for (int k = strlen(tmp), l = i; k >= 0; k--, l++) {
				str[l] = tmp[k];
			}
			prevDiv = i;
		}
	}
}

int main()
{
	char *str = new char[255];

	reverseWords(str);

	cout << str;

	delete[] str;
    return 0;
}

