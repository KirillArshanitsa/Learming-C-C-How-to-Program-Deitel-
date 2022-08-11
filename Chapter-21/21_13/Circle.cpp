#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(unsigned int r)
{
	if (r == 0) {
		cout << "Error, radius must be rather than 0." << endl;
		radius = 1;
	}
	else
		radius = r;
}



double Circle::getArea()
{
	return 3.14 * radius * radius;
}