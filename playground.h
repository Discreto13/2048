#pragma once
#include <cstdlib>
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
	friend void display(const playground &);
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
	
private:
	unsigned short int itsSize;
	unsigned int ** itsArray;
};
