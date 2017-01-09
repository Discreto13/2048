#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class playground
{
public:
	playground(unsigned short int);
	~playground();
	void initialization();
	class coordinates;
	bool generate();
	void display();
	bool moveUp();
	
private:
	unsigned short int itsSize;
	unsigned int ** itsArray;


};