#include <iostream>
#include "playground.h"
using namespace std;

int main(char argc, char* argv[])
{
	//cout << "Game 2048" << endl;
	playground PG(4);
	PG.initialization();
	PG.display();
	for (int i = 0; i < 100; i++)
	{
		cin.ignore();
		system("cls");
		if (!PG.generate()) { cout << "Array is fill!" << endl; }
		PG.display();

		cin.ignore();
		system("cls");
		if (!PG.moveUp()) { cout << "Array not moved!" << endl; }
		PG.display();
	}
	cin.ignore();
}