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

bool RationalNumber::operator>(const RationalNumber& another) const
{
	return (double)denominator / (double)numerator > (double) another.denominator / (double)another.numerator;
}

bool RationalNumber::operator>=(const RationalNumber& another) const
{
	if ((*this) == another)
		return true;
	else
		return (*this) > another;
}

bool RationalNumber::operator==(const RationalNumber& another) const
{
	if (numerator != another.numerator)
		return false;
	if (denominator != another.denominator)
		return false;
	return true;
}


int RationalNumber::getNod(int numerator, int denominator)
{
	if (denominator > numerator) {
		int remainder = denominator % numerator;
		while (remainder) {
			if (numerator % remainder) {
				denominator = remainder;
				remainder = numerator % remainder;
				numerator = denominator;
				if (numerator < remainder)
					return 0;
			}
			else
				return remainder;
		}
		return numerator;
	}
	else {
		int remainder = numerator % denominator;
		while (remainder) {
			if (denominator % remainder) {
				numerator = remainder;
				remainder = denominator % remainder;
				denominator = numerator;
				if (denominator < remainder)
					return 0;
			}
			else
				return remainder;
		}
		return denominator;
	}
}

void RationalNumber::print()
{
	cout << "numerator=" << numerator << endl;
	cout << "denominator=" << denominator << endl;
}

void RationalNumber::operator+(const RationalNumber &anotherRationalNumber)
{
	numerator += anotherRationalNumber.numerator;
	if (denominator != anotherRationalNumber.denominator)
		denominator += anotherRationalNumber.denominator;

}


void RationalNumber::operator-(const RationalNumber& anotherRationalNumber)
{
	numerator -= anotherRationalNumber.numerator;
	if (denominator != anotherRationalNumber.denominator)
		denominator -= anotherRationalNumber.denominator;
}

void RationalNumber::operator*(const RationalNumber& anotherRationalNumber)
{
	numerator *= anotherRationalNumber.numerator;
	denominator *= anotherRationalNumber.denominator;

	fractionReduction();
}


void RationalNumber::operator/(const RationalNumber& anotherRationalNumber)
{
	RationalNumber copy = RationalNumber(anotherRationalNumber.denominator, anotherRationalNumber.numerator);
	(*this) * copy;
}


void RationalNumber::fractionReduction()
{
	int remainder = getNod(numerator, denominator);
	if (remainder) {
		numerator = numerator / remainder;
		denominator = denominator / remainder;
	}

}