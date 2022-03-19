#include "Date.h"
//#include <iostream>
//
//using std::cout;
//using std::endl;

int main()
{
	Date date(19, 3, 2022);
	//Date date;
	date.print();

	for (int i = 0; i < 381; i++) {
		date.nextDay();
		date.print();
	}

	return 0;
}