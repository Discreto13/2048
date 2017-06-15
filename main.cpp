#include <iostream>
#include <string>
#include <conio.h>
#include "playground.h"
using namespace std;

void display(const playground & PG)
{
	cout << "Score: " << PG.score << endl;

	for (int i = 0; i < PG.itsSize; i++)
	{
		for (int j = 0; j < 8 * PG.itsSize + 1; j++)
		{
			cout << "-";
		}
		cout << endl;
		
		for (int j = 0; j < PG.itsSize; j++)
		{
			cout << "|\t";
		}
		cout << "|";
		cout << endl;
		
		for (int j = 0; j < PG.itsSize; j++)
		{
			cout << "|  " << PG.itsArray[i][j] << "\t";
		}
		cout << "|";
		cout << endl;
		
		for (int j = 0; j < PG.itsSize; j++)
		{
			cout << "|\t";
		}
		cout << "|";
		cout << endl;
	}
	
	for (int i = 0; i < 8 * PG.itsSize + 1; i++)
	{
		cout << "-";
	}
}

int main(int argc, char* argv[])
{
	cout << "Game 2048";
	cin.ignore();
	system("cls");
	playground PG(4);
	PG.initialization();
	PG.generate();
	string message;
	bool(playground::*move)() = 0;
	while (true)
	{
		system("cls");
		display(PG);
		if (PG.gameOver()) break;
		if (message.length() != 0) cout << message << endl, message.clear();
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
		if (!(PG.*move)()) { message += "\nMatrix not moved!"; }
		else { PG.generate(); }
	}
	//game over
	//cout << yourScore;
	cout << "\nGame over!";
	cin.ignore();
}