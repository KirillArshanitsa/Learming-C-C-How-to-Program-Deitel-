#include "Time.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
	Time timeDefConstr;
	Time time(10, 30 ,00);
	timeDefConstr.printStandard();
	timeDefConstr.printUniversal();
	time.printStandard();
	time.printUniversal();

}