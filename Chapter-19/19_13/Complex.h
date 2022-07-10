#ifndef COMPLEX_H 
#define COMPLEX_H 

#include <iostream>
using std::ostream;
using std::istream;

class Complex
{
	friend istream &operator>>(istream&, Complex&);
	friend ostream &operator<<(ostream&, const Complex&);
public:
	Complex(double = 0.0, double = 0.0); // конструктор 
	Complex operator+(const Complex&) const; // сложение 
	Complex operator-(const Complex&) const; // вычитение 
	bool operator==(const Complex&) const;
	bool operator!=(const Complex& complex) const
	{
		return !(*this == complex);
	}
	Complex operator*(const Complex&) const;
private:
	double real; // действительная часть 
	double imaginary; // мнимая часть 
}; // конец класса Complex 

#endif 
