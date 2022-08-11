#ifndef CUBE_H
#define CUBE_H
#include "ThreeDimensionalShape.h"

class Cube : public ThreeDimensionalShape
{
public:
	Cube(double);
	virtual double getVolume();
	virtual double getArea();

private:
	double sideSize;
};

#endif // !CUBE_H
