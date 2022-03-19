#include "Time.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
	Time time(11, 58, 50);
	time.printStandard();

	for (int i = 0; i < 300; i++) {
		cout << "tick" << endl;
		time.tick();
		time.printStandard();
	}


}