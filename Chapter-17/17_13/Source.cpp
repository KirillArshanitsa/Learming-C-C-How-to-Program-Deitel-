#include "Rectangle.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{

	rectangle rect(3,7, 7,7, 3,2, 7,2);
	//cout << "rectangle area = " << rect.area() << endl;
	//cout << "rectangle perimeter = " << rect.perimeter() << endl;
	//cout << "rectangle square = " << rect.square() << endl;
	rect.setFillCharacter('s');
	rect.setPerimeterCharacter('A');
	rect.draw();

	//rectangle defaultRect(8,10, 12,10, 8,7, 12,7);
	//defaultRect.draw();

	return 0;
}