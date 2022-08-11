#include "Cube.h"
#include<iostream>

using namespace std;

Cube::Cube(double s)
{
	if (s < 0) {
		cout << "Error, side size must be rather than 0." << endl;
		sideSize = 1;
	}
	else
		sideSize = s;
}

double Cube::getArea()
{
	return 6 * sideSize * sideSize;
}

double Cube::getVolume()
{
	return sideSize * sideSize * sideSize;
}