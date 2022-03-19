#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle
{
public:
	rectangle(double = 1, double = 1);
	double perimeter();
	double area();
	void setWidth(double);
	void setLength(double);

private:
	double width;
	double length;
};
#endif 
