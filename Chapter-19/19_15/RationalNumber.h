#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H


class RationalNumber
{
public:
	RationalNumber(int, int);
	bool isEquals(const RationalNumber &) const;
	void print();

private:
	int numerator;
	int denominator;
	void fractionReduction();
};

#endif 
