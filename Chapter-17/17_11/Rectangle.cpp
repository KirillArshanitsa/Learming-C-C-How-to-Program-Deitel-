#include "Rectangle.h"

rectangle::rectangle(double w, double l)
{
	setLength(l);
	setWidth(w);
}

void rectangle::setLength(double l)
{
	if ((l >= 0) && (l <= 20))
		length = l;
}

void rectangle::setWidth(double w)
{
	if ((w >= 0) && (w <= 20))
		width = w;
}


double rectangle::area()
{
	return width * length;
}


double rectangle::perimeter()
{
	return 2 * (width + length);
}