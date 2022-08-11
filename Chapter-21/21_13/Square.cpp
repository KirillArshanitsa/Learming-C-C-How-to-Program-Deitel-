#include "Square.h"
#include "iostream"

using namespace std;

Square::Square(unsigned int sideSize)
{
	if (sideSize == 0) {
		cout << "Error, sideSquare must be rather than 0." << endl;
		sideSquare = 1;
	}
	else
		sideSquare = sideSize;
}


double Square::getArea()
{
	return sideSquare * sideSquare;
}