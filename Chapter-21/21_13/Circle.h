#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape
{
public:
	Circle(unsigned int);
	virtual double getArea();

private:
	unsigned int radius;
};
#endif // !CIRCLE_H
