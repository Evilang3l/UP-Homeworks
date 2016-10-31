// KnightTour.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int N = 5;
const int startX = 1;
const int startY = 1;

int moves[2][8] = { { 1,  2,  2, 1, -1, -2, -2, -1 },
						  { -2, -1, 1, 2, -2, -1,  1,  2 } };  //�������� ������

int table[N][N] = { 0 };

bool isMoveOK(int x, int y)
{
	if (x < N && x >= 0 && y < N && y >= 0 && table[x][y] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool tourPossible(int x, int y, int step)
{
	table[x][y] = step;
	if (step == N*N) 
	{
		return true; // ��� ��� ������� ������ �����, �������� �� ���������.
	}
	else
	{
		for (int i = 0; i < 8; i++) // ����� �� 0 �� 7, ������ ����� 8 ���������� �� �����������.
		{
			{
				if ((isMoveOK(x + moves[0][i], y + moves[1][i])) == true) // ����������� �� ����� ��� ���� �������� ��� � ��������.
				{
					//������ � ��������, ��������� ���������� ��������� �� �������� "������".
					if ((tourPossible(x + moves[0][i], y + moves[1][i], step + 1)) == true)
					{
						return true;
					}
					//��� �� ������� �� ������� � �������� ����������� �� ����, ������������ ��� ���������.
				}
			}
		}
		table[x][y] = 0; // ��� �� ��� ���������� �� ������� ��� ������������� ������ �� "���������".
	}
	return false;
}

int main()
{
	
	bool isTourPossible = tourPossible(startX - 1, startY - 1, 1);

	if (isTourPossible) cout << "Tour exists!" << endl;
	else cout << "Tour does not exist" << endl;

	return 0;
}