// Zadacha1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
int main()
{
	int* output;
	int input;
	cin >> input;  
	output = new int[input];

	for (int i = 0; i < input; i++) {
		output[i] = i + 1;
	}

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			if (i == 0 || i == input - 1) {
				if(output[j] <= 9) cout << output[j] << "  ";
				else cout << output[j] << " ";
				
			}
			else {
				if (j == 0) {
					cout << 1 << "  ";
				}
				if (j == input - 1) {
					cout << input;
				}
				if (j != 0 && j != input - 1) {
					if (i == j || j == input - 1 - i) {
						if(output[j] <= 9) cout << output[j] << "  ";
						else cout << output[j] << " ";
					}
					else {
						cout << "   ";
					}
				}
			}
		}
		cout << endl;
	}

	return 0;
}


