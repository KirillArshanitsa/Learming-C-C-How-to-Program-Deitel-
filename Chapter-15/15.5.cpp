#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const double PI = 3.14159;

inline double circleArea(double radius) 
{
	return radius * radius * PI;
}

int main() 
{
	double radius;
	cout << "Enter radius:";
	cin >> radius;
	cout << "Area of a circle is " << circleArea(radius) << endl;
	return 0;
}
