#include <iostream>
#include <string>
#include <conio.h>
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

int main(char argc, char* argv[])
{
	//cout << "Game 2048" << endl;
	playground PG(4);
	PG.initialization();
	PG.generate();
	display(PG);
	string message;
	bool(playground::*move)() = 0;
	while (true)
	{
		message.clear();
		_getch();
		switch (_getch())
		{
		case 72://up
			move = &playground::moveUp;
			break;
		case 80://down
			move = &playground::moveDown;
			break;
		case 75://left
			move = &playground::moveLeft;
			break;
		case 77://right
			move = &playground::moveRight;
			break;
		default:
			move = 0;
			break;
		}
		if (!move) { continue; }
		if (!(PG.*move)()) { message += "Array not moved!\n"; }
		else if (!PG.generate()) { message += "Array is fill!\n"; }
		system("cls");
		display(PG);
		cout << message;
	}
	cin.ignore();
}