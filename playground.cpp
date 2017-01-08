#include "playground.h"

playground::playground(unsigned short int size):
	itsSize(size)
{
	itsArray = new unsigned int * [itsSize];
	for (int i = 0; i < itsSize; i++)
	{
		itsArray[i] = new unsigned int [itsSize];
	}
}

playground::~playground()
{
	for (int i = 0; i < itsSize; i++)
	{
		delete[] itsArray[i];
	}
	delete[] itsArray;
}

void playground::initialization()//every element in array is 0
{
	//!!!можно добавить исключение на случай, если массив не создан!!!
	for (int  i = 0; i < itsSize; i++)
	{
		for (int j = 0; j < itsSize; j++)
		{
			itsArray[i][j] = 0;
		}
	}
}

bool playground::generate()//false - if not enough space for create new element
{
	return 0;
}

void playground::display()
{
	for (int i = 0; i < itsSize; i++)
	{
		for (int j = 0; j < itsSize; j++)
		{
			cout << itsArray[i][j] << "\t";
		}
		cout << endl;
	}
}
