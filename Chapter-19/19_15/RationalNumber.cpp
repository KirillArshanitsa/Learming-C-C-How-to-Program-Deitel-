#include "RationalNumber.h"
#include <iostream>

using std::cout;
using std::endl;

RationalNumber::RationalNumber(int numerator, int denominator)
{
	if (denominator <= 0) {
		(*this).denominator = 1;
		cout << "You enter " << denominator << " denominator = 1" << endl;
	}
	(*this).numerator = numerator;
	(*this).denominator = denominator;
	fractionReduction();
}

void RationalNumber::fractionReduction()
{
	if (denominator % numerator == 0) {
		denominator = denominator / numerator;
		numerator = 1;
	}
	//else if (denominator / numerator > 0) {
	//	int tmp = denominator / numerator;
	//	numerator = numerator / tmp;
	//	denominator = denominator / tmp;
	//}
	else if (denominator % numerator) {
		int tmp = denominator % numerator;
		numerator = numerator / tmp;
		denominator = denominator / tmp;
	}
}

void RationalNumber::print()
{
	cout << "numerator=" << numerator << endl;
	cout << "denominator=" << denominator << endl;

}