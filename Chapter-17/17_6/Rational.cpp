#include "Rational.h"
#include <iostream>

using std::cout;
using std::endl;

Rational::Rational(int num, int denom)
{
	if (denom % num == 0) {
		numerator = 1;
		denominator = denom / num;
	}
	else {
		numerator = num;
		denominator = denom;
	}
}

void Rational::sum(int num, int denom)
{
	if (denominator == denom) {
		numerator += num;
	}
	else {
		numerator = numerator * denom + num * denominator;
		denominator = denom * denominator;
	}
}

void Rational::subtraction(int num, int denom)
{
	if (denominator == denom) {
		numerator -= num;
	}
	else {
		numerator = numerator * denom - num * denominator;
		denominator = denom * denominator;
	}
}

void Rational::multiplication(int num, int denom)
{
	numerator *= num;
	denominator *= denom;
}

void Rational::division(int num, int denom)
{
	numerator *= denom;
	denominator *= num;
}


void Rational::printRationalNum()
{
	cout << numerator << "/" << denominator << endl;
}

void Rational::printRationalDouble()
{
	cout << (double) numerator / (double) denominator << endl;
}