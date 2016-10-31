#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int lastIdPlayer = -1;
int lastIdCard = -1;

enum Color {
	Red,
	Black,
	Blue,
	White,
	Green
};

struct Players {
	char name[128];
	unsigned Id;
};

Players* igrachi[1 << 15];

struct Cards {
	unsigned IdCard;
	char name[64];
	Color color;

};

Cards* karti[1 << 15];

struct Decks {
	unsigned IdPlayer;
	unsigned IdCards[60];
	Color DeckColor;
};

void CheckColor(char* tempInput, Cards card) {
	if (strcmp(tempInput, "Red") == 0) card.color = Red;
	else if (strcmp(tempInput, "Black") == 0) card.color = Red;
	else if (strcmp(tempInput, "Blue") == 0) card.color = Blue;
	else if (strcmp(tempInput, "White") == 0) card.color = White;
	else if (strcmp(tempInput, "Green") == 0) card.color = Green;
	else cout << "Not valid Color";
}

void CcCommand() {

	lastIdCard++;
	char* tempInput = NULL;
	cin.getline(tempInput, 10, ' ');
	karti[lastIdCard] = new Cards;
	CheckColor(tempInput, *karti[lastIdCard]);
	tempInput = NULL;
	cin.getline(tempInput, 64);

	strcpy_s(karti[lastIdCard]->name, tempInput);
	karti[lastIdCard]->IdCard = lastIdCard;
	cout << karti[lastIdCard]->color << " " << karti[lastIdCard]->IdCard << " " << karti[lastIdCard]->name << endl;
	ofstream myfile("cards.dat", ios::binary | ios::app);
	if (myfile.is_open()) {
		myfile.write((char*)&karti[lastIdCard], sizeof(karti[lastIdCard]));
	}
	else
	{
		ofstream file("cards.dat", ios::binary);
		file.close();
	}
	myfile.close();
}


void CpCommand()
{
	lastIdPlayer++;
	igrachi[lastIdPlayer] = new Players;
	cin.getline(igrachi[lastIdPlayer]->name, 128);
	igrachi[lastIdPlayer]->Id = lastIdPlayer;
	cout << igrachi[lastIdPlayer]->name << endl;
	cout << igrachi[lastIdPlayer]->Id << endl;
	ofstream myfile("players.dat", ios::binary | ios::app | ios::ate);
	if (myfile.is_open()) {
		myfile.write((char*)&igrachi[lastIdPlayer], sizeof(igrachi[lastIdPlayer]));
	}
	else
	{

		ofstream file("players.dat", ios::binary);
		file.close();
	}
	myfile.close();

}

void loadPlayers()
{
	ifstream playerFile;
	playerFile.open("players.dat", ios::binary);
	if (playerFile.is_open()) {

		while (true)
		{
			lastIdPlayer++;
			igrachi[lastIdPlayer] = new Players;
			playerFile.read((char*)igrachi[lastIdPlayer], sizeof(igrachi[lastIdPlayer]));
			cout << igrachi[lastIdPlayer]->name << endl;
			if (playerFile.eof())
				break;
		}
		playerFile.close();
	}
	else
	{
		ofstream playerFile("players.dat", ios::binary);
		playerFile.close();
	}

}

void LoadCards()
{
	ifstream cardsFile;
	cardsFile.open("cards.dat", ios::binary);
	if (cardsFile.is_open())
	{
		while (true)
		{
			lastIdCard++;
			karti[lastIdCard] = new Cards;
			cardsFile.read((char*)karti[lastIdCard], sizeof(karti[lastIdCard]));
			if (cardsFile.eof())
			{
				break;
			}

		}
	}
	else
	{
		ofstream cardsFile("cards.dat", ios::binary);
	}
	cardsFile.close();
}

void CheckCommand()
{
	char buffer[20];
	cin.getline(buffer, 20);
	if (strcmp(buffer, "cc") == 0) cout << "cc command" << endl;
	else if (strcmp(buffer, "cd") == 0)
		cout << "cd command" << endl;
	else if (strcmp(buffer, "cp") == 0) {
		cout << "cp command" << endl;
		CpCommand();
	}
	else if (strcmp(buffer, "report") == 0)
		cout << "report command" << endl;
	else if (strcmp(buffer, "players") == 0)
	{
		for (int i = 0; i <= lastIdPlayer; i++)
		{
			cout << igrachi[i]->name << endl;
		}
	}
	else if (strcmp(buffer, "cards") == 0)
	{
		for (int i = 0; i <= lastIdCard; i++)
		{
			cout << karti[i]->name << " " << karti[i]->color << " " << karti[i]->IdCard << endl;
		}
	}
	else {
		cout << "Wrong command!";
		//return;
	}
	CheckCommand();
}

int main()
{
	loadPlayers();
	LoadCards();
	CheckCommand();
	/* for (int i = 0; i <= lastIdPlayer; ++i) {
	delete igrachi[i];
	}
	*/
	return 0;
}