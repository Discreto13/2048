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

int main(char argc, char* argv[])
{
	//cout << "Game 2048" << endl;
	playground PG(4);
	PG.initialization();
	display(PG);
	string message;
	for (int i = 0; i < 20; i++)
	{
		message.clear();
		cin.ignore();
		if (!PG.moveUp()) { message += "Array not moved!\n"; }
		if (!PG.generate()) { message += "Array is fill!\n"; }
		system("cls");
		display(PG);
		cout << message;
	}
	cin.ignore();
}