#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle
{
public:
	rectangle(double, double , double, double , double , double, double, double);
	void setRectangle(double, double, double, double, double, double, double, double);
	double perimeter();
	double area();
	double getWidth();
	double getLength();
	bool square();

private:
	double aX; double aY; double bX; double bY; double cX; double cY; double dX; double dY;
};
#endif 
