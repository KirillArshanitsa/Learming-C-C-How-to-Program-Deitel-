#include "Rectangle.h"
#include <iostream>

using std::cout;
using std::endl;

rectangle::rectangle(double aX, double aY, double bX, double bY, double cX, double cY, double dX, double dY)
{
	setRectangle(aX, aY, bX, bY, cX, cY, dX, dY);
}



void rectangle::setRectangle(double aXlocal, double aYlocal, double bXlocal, double bYlocal, double cXlocal, double cYlocal, double dXlocal, double dYlocal)
{
	if (((aYlocal == bYlocal) && (cYlocal == dYlocal) && (aXlocal == cXlocal) && (bXlocal == dXlocal)) && ((aYlocal != cYlocal) && (bYlocal != dYlocal) && (aXlocal != bXlocal) && (cXlocal != dXlocal))) {
		int listCoordinates[8] = { aXlocal, aYlocal, bXlocal, bYlocal, cXlocal, cYlocal, dXlocal, dYlocal };

		for (int i = 0; i < 8; i++) {
			if ((listCoordinates[i] < 0) || (listCoordinates[i] > 20)) {
				cout << "Coordinates must be 0 - 20" << endl;
				return;
			}
		}
		aX = aXlocal; aY = aYlocal; bX = bXlocal; bY = bYlocal; cX = cXlocal; cY = cYlocal; dX = dXlocal; dY = dYlocal;
	}
	else {
		cout << "This is not a rectangle" << endl;
	}

}

double rectangle::getWidth()
{
	double y = bX - aX;
	double x = aY - cY;
	if (x > y)
		return y;
	else
		return x;

}

double rectangle::getLength()
{
	double y = bX - aX;
	double x = aY - cY;
	if (x > y)
		return x;
	else
		return y;
};


double rectangle::area() 
{
	double y = bX - aX;
	double x = aY - cY;

	return x * y;
}


double rectangle::perimeter()
{
	double y = bX - aX;
	double x = aY - cY;

	return 2 * (x + y);
}

bool rectangle::square()
{
	double y = bX - aX;
	double x = aY - cY;

	return x == y;
}