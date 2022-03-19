#include "DateAndTime.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
	DateAndTime dateAndTime(23, 58, 50, 03, 19, 2022);
	dateAndTime.printStandard();
	dateAndTime.printUniversal();

	for (int i = 0; i < 300; i++) {
		cout << "tick" << endl;
		dateAndTime.tick();
		dateAndTime.printStandard();
		dateAndTime.printUniversal();
		cout << endl;
	}


}