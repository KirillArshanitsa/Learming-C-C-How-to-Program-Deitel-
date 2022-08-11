#ifndef SQUARE_H
#define SQUARE_H

#include "TwoDimensionalShape.h"

class Square : public TwoDimensionalShape
{
public:
	Square(unsigned int);
	virtual double getArea();

private:
	unsigned int sideSquare;
};

#endif // !SQUARE_H
