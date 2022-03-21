#include "Rectangle.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	//rectangle rect(1,21, 3,21, 1,1, 3,1);

	rectangle rect(1,3, 3,3, 1,1, 3,1);
	cout << "rectangle area = " << rect.area() << endl;
	cout << "rectangle perimeter = " << rect.perimeter() << endl;
	cout << "rectangle square = " << rect.square() << endl;
	return 0;
}