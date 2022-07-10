#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

#include "Complex.h" 

int main()
{
	Complex x;
	Complex y(4.3, 8.2);
	Complex z(3.3, 1.1);

	cout << endl;
	cout << y;
	cin >> y;
	cout << endl;
	cout << y;

	cout << endl;
	cout << y * z;

	cout << endl;
	cout << y + z;

	cout << endl;
	bool i = y != z;
	cout << i;

}