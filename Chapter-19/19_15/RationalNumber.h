#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H


class RationalNumber
{

public:
	RationalNumber(int, int);
	void print();
	int getNod(int, int);
	void fractionReduction();
	void operator+(const RationalNumber &);
	void operator-(const RationalNumber &);
	void operator*(const RationalNumber &);
	void operator/(const RationalNumber &);
	bool operator==(const RationalNumber&) const;
	bool operator>(const RationalNumber&) const;
	bool operator<(const RationalNumber &another) const {
		return another > (*this);
	}
	bool operator>=(const RationalNumber&) const;
	bool operator<=(const RationalNumber & another) const {
		return another >= (*this);
	}

private:
	int numerator;
	int denominator;
};

#endif 
