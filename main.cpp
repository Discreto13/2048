#include <iostream>
#include <string>
#include "playground.h"
using namespace std;

void display(const playground & PG)
{
	for (int i = 0; i < PG.itsSize; i++)
	{
		for (int j = 0; j < PG.itsSize; j++)
		{
			cout << PG.itsArray[i][j] << "\t";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	//cout << "Game 2048" << endl;
	system("clear");
	playground PG(4);
	PG.initialization();
	PG.generate();
	display(PG);
	string message;
	bool(playground::*move)() = 0;
	char choice = 0;
	while (true)
	{
		message.clear();
		cin >> choice;
		switch (choice)
		{
		case 'u'://up
			move = &playground::moveUp;
			break;
		case 'd'://down
			move = &playground::moveDown;
			break;
		case 'l'://left
			move = &playground::moveLeft;
			break;
		case 'r'://right
			move = &playground::moveRight;
			break;
		default:
			move = 0;
			break;
		}
		if (!move) { continue; }
		if (!(PG.*move)()) { message += "Array not moved!\n"; }
		else if (!PG.generate()) { message += "Array is fill!\n"; }
		system("clear");
		display(PG);
		cout << message;
	}
	cin.ignore();
	return 0;
}
