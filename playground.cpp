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
	srand(time(NULL));
	for (int  i = 0; i < itsSize; i++)
	{
		for (int j = 0; j < itsSize; j++)
		{
			itsArray[i][j] = 0;
		}
	}
}

class playground::coordinates//private class
{
public:
	coordinates(unsigned short int na, unsigned short int nb) : a(na), b(nb) {}
	void setCoord(unsigned short int na, unsigned short int nb)// n - new
	{
		a = na;
		b = nb;
	}
	void getCoord(unsigned short int & ta, unsigned short int & tb)//t - temp
	{
		ta = a;
		tb = b;
	}
private:
	unsigned short int a;
	unsigned short int b;
};

//false - if not enough space for create new element
bool playground::generate()
{
	//save coordinates empty-elements, 
	//and select random

	coordinates tempCoord(0, 0);
	vector<coordinates> list;
	for (int i = 0; i < itsSize; i++)
		for (int j = 0; j < itsSize; j++)
			if (itsArray[i][j] == 0)
			{
				tempCoord.setCoord(i, j);
				list.push_back(tempCoord);
			}
	unsigned int listSize = list.size();
	if (!listSize) {return 0;}
	tempCoord = list[rand()%listSize];
	unsigned short int a, b;
	tempCoord.getCoord(a, b);
	itsArray[a][b] = (rand()%2)?2:4;
	return 1;
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

bool playground::moveUp()
{
	bool arrayMoved = false;//array is moved
	//check all elements
	for (int i = 0; i < itsSize; i++)
	{
		for (int j = 0; j < itsSize; j++)
		{
			//move to down from element
			for (int k = i + 1; k < itsSize; k++)
			{
				//if "down-element" != 0, then
				if (itsArray[k][j] != 0)
				{
					if (itsArray[i][j] == 0 || itsArray[i][j] == itsArray[k][j])
					{
						itsArray[i][j] += itsArray[k][j];
						itsArray[k][j] = 0;
						arrayMoved = true;
					}
					break;
				}
			}
		}
	}
	return arrayMoved;
	//itsArray[i][j] - current element
	//itsArray[k][j] - current down-element form main-element
}