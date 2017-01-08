#pragma once
#include <iostream>
using namespace std;

class playground
{
public:
	playground(unsigned short int);
	~playground();
	void initialization();
	bool generate();
	void display();
private:
	unsigned short int itsSize;
	unsigned int ** itsArray;
};