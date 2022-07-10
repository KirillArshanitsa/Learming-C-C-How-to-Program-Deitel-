#include <iostream> 
using std::cout;
using std::endl;

#include "Complex.h" // определение класса Complex 

// конструктор 
Complex::Complex(double realPart, double imaginaryPart)
	: real(realPart),
	imaginary(imaginaryPart)
{
	// пустое тело 
} // конец конструктора Complex 

// операция сложения 
Complex Complex::operator+(const Complex& operand2) const
{
	return Complex(real + operand2.real,
		imaginary + operand2.imaginary);
} // конец функции operator+ 

// операция вычитания 
Complex Complex::operator-(const Complex& operand2) const
{
	return Complex(real - operand2.real,
		imaginary - operand2.imaginary);
} // конец функции operator- 

bool Complex::operator==(const Complex& complex) const
{
	if (real != complex.real)
		return false;
	if (imaginary != complex.imaginary)
		return false;

	return true;
}

Complex Complex::operator*(const Complex& complex) const
{
	double realN = real * complex.real - imaginary * complex.imaginary;
	double imaginaryN = real * complex.imaginary + imaginary * complex.real;
	return Complex(realN, imaginaryN);
}

ostream& operator<<(ostream& output, const Complex &complex)
{
	output << '(' << complex.real << ", " << complex.imaginary << ')';
	return output;
}

istream& operator>>(istream& input, Complex& complex)
{
	cout << "\nEnter real and imaginary:" << endl;
	input >> complex.real;
	input >> complex.imaginary;
	return input;
}