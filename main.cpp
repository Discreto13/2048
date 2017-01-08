#include <iostream>
#include "playground.h"
using namespace std;

int main(char argc, char* argv[])
{
	cout << "Game 2048" << endl;
	playground PG(4);
	PG.display();
	PG.initialization();
	PG.display();
	cin.ignore();
}