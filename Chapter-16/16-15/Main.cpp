#include "Date.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
	Date testDate(12, 3, 2022);
	cout << "Tests:\ngetDay() = " << testDate.getDay() << "\ngetMonth() = " << testDate.getMonth() << "\netYear() = " << testDate.getYear() << endl;
	cout << "displayDate() = ";
	testDate.displayDate();
	cout << "\nSet changes" << endl;
	testDate.setDay(12);
	testDate.setMonth(22);
	testDate.setYear(2012);
	testDate.displayDate();

	cout << "After changes displayDate() = ";
	testDate.displayDate();
}