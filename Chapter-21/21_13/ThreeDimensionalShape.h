#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H

#include "Shape.h"

class ThreeDimensionalShape : public Shape
{
public:
	virtual double getVolume() = 0;
};

#endif // !THREEDIMENSIONALSHAPE_H
