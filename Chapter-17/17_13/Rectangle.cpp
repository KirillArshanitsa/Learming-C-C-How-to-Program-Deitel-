#include "Rectangle.h"
#include <iostream>

using std::cout;
using std::endl;

rectangle::rectangle(double aX, double aY, double bX, double bY, double cX, double cY, double dX, double dY)
{
	setRectangle(aX, aY, bX, bY, cX, cY, dX, dY);
	setFillCharacter('s');
	setPerimeterCharacter('*');
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


void rectangle::setFillCharacter(char c)
{
	fillCharacter = c;
}

void rectangle::setPerimeterCharacter(char c)
{
	perimeterCharacter = c;
}

void rectangle::draw()
{
	double lengthLine = bX - aX;
	double widthLine = aY - cY;


	//print frame 25 * 25
	char frameSymbolLine = '_';
	char frameSymbolFront = '|';
	char length = 25 * 2;
	char width = length / 2;
	length++;
	char leftWidthLine = widthLine - 2;
	char beginLinePoint = aY;
	char endLinePoint = cY;
	
	if (width % 100) // prin 3 space
		cout << "   ";
	else
		cout << " ";
	for (int l = 0; l < length; l++) {
		cout << frameSymbolLine;
	}
	cout << endl;
	for (int l = width; l > 0; l--) {
		if (l < 10)
			cout << " " << l;
		else
			cout << l;
		cout << frameSymbolFront;
		for (int i = 1; i <= length; i++) {
			if ((aX == i) && ((aY == l) || (cY == l))) {
				printLine(perimeterCharacter, lengthLine);
				i = i + lengthLine;
			}
			else if ( (aX == i || bX == i) && (beginLinePoint > l && l > endLinePoint) )
				cout << perimeterCharacter;
			else if ( (aX < i && i < bX ) && (beginLinePoint > l && l > endLinePoint) )
				cout << fillCharacter;
			else
				cout << ' ';
		}
		cout << frameSymbolFront << endl;
	}

	cout << " 0" << frameSymbolFront;
	for (int l = 0; l < length; l++) 
		cout << frameSymbolLine;

	cout << frameSymbolFront << endl;


	cout << "   0";
	for (int l = 1; l <= width; l++) {
		if (l < 10) {
			cout << " ";
		}
		cout << l;
	}
	cout  << endl;
}


void rectangle::printLine(char symbol, int size)
{
	for (int l = 0; l <= size; l++)
		cout << symbol;
}