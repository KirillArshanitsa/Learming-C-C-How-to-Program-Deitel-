#include "Rectangle.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	rectangle rect(2, 5.1);
	cout << "rectangle area = " << rect.area() << endl;

	cout << "rectangle area = " << rect.area() << endl;
	cout << "rectangle perimeter = " << rect.perimeter() << endl;
	return 0;
}