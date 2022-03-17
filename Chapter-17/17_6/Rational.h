#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
	Rational(int = 1, int = 1);
	void sum(int, int);
	void subtraction(int, int);
	void multiplication(int, int);
	void division(int, int);
	void printRationalNum();
	void printRationalDouble();

private:
	int numerator;
	int denominator;
};

#endif 
