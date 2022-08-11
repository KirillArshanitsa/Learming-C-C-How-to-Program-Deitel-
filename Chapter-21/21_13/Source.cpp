#include "Shape.h"
#include "Circle.h"
#include "Cube.h"
#include "Square.h"

#include <vector>
#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	vector < Shape * > shapes(3);
	shapes[0] = new Circle(2);
	shapes[1] = new Cube(3);
	shapes[2] = new Square(4);

	for (size_t i = 0; i < shapes.size(); i++) {
		ThreeDimensionalShape* derivedPtr = dynamic_cast<ThreeDimensionalShape*>(shapes[i]);
		cout << shapes[i]->getArea() << endl;
		if (derivedPtr != 0) 
			cout << "getVolume() = " << derivedPtr->getVolume() << endl;
		
	}

	return 0;
}
