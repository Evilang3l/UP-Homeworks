// Zadacha3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"

using namespace std;

int main()
{
	int inputNum1 = 0, inputNum2 = 0, binaryNum1[32], binaryNum2[32], checker = 0, octetDecValue = 0, prefixCount = 0, prefixBinary[32], prefixDecValue = 0;

	cin >> inputNum1 >> inputNum2;

	//Превръшаме числата от десетична в дройчна бройна система
	for (int i = 31; i >= 0; i--)
	{
		checker = inputNum1 >> i;

		if (checker & 1)
			binaryNum1[31 - i] = 1;
		else
			binaryNum1[31 - i] = 0;
	}

	checker = 0;

	for (int i = 31; i >= 0; i--)
	{
		checker = inputNum2 >> i;

		if (checker & 1)
			binaryNum2[31 - i] = 1;
		else
			binaryNum2[31 - i] = 0;
	}
	//

	//Превръщаме числата от 32-битови двоични в IP адрес като ги разделим на 4 октета по 8 бита всеки
	cout << "Octets: ";
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 8; k++) {
			if(binaryNum1[i*8 + k] == 1) octetDecValue += pow(2.0, (double)(7 - k));
		}
		if(i != 3) cout << octetDecValue << ".";
		else cout << octetDecValue << "; ";
		octetDecValue = 0;
	}

	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 8; k++) {
			if (binaryNum2[i * 8 + k] == 1) octetDecValue += pow(2.0, (double)(7 - k));
		}
		if (i != 3) cout << octetDecValue << ".";
		else cout << octetDecValue << ";" << endl;
		octetDecValue = 0;
	}
	//

	//Проверяваме броя на съвпадащата "битова представка" на двете IP-та
	for (int i = 0; i < 32; i++) {
		if (binaryNum1[i] == binaryNum2[i]) prefixCount++;
		else break;
	}

	cout << "Prefix length: " << prefixCount << "; \n";
	//

	//Представяме съвпадащата представка като маска на IP адрес
	cout << "Prefix binary: ";
	for (int i = 0; i < 32; i++) {
		if(i < prefixCount) prefixBinary[i] = 1;
		else prefixBinary[i] = 0;
		cout << prefixBinary[i];
	}
	cout << "; \n";
	//

	//Обръщаме маската в десетична бройна система (от 32 бита - на 4 октета по 8 бита)
	cout << "Prefix octets: ";
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 8; k++) {
			if (prefixBinary[i * 8 + k] == 1) prefixDecValue += pow(2.0, (double)(7 - k));
		}
		if (i != 3) cout << prefixDecValue << ".";
		else cout << prefixDecValue << "; ";
		prefixDecValue = 0;
	}
	cout << "\n";
	//

    return 0;
}

