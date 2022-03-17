#include "Rational.h"


int main()
{
	Rational rational(2, 4);
	rational.printRationalDouble();
	rational.printRationalNum();

	rational.sum(3, 6);
	rational.printRationalDouble();
	rational.printRationalNum();
	return 0;
}