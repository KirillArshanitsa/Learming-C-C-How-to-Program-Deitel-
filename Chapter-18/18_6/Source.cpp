#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

int main()
{
	cout <<"Result from a:" << endl;
	Date date1(6, 14, 1992);
	date1.print();
	cout << endl;
	cout << endl;
	cout << "Result from b:" << endl;
	Date date2("006 1992");
	date2.print();
	Date date3("2/14/92");
	date3.print();
	Date date4("June 14, 1992");
	date4.print();
	cout << endl;
	cout << endl;
	cout << "Result from c:" << endl;
	Date date5;
	date5.print();
	return 0;
}
