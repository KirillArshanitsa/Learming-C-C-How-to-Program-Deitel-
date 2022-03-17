#include "Complex.h"
#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

Complex::Complex(double realPartNum, double imaginaryPartNum)
{
    realPart = realPartNum;
    imaginaryPart = imaginaryPartNum ;
}

void Complex::sum(double realPartNum, double imaginaryPartNum)
{
    cout << realPart + realPartNum << " " << imaginaryPart + imaginaryPartNum << "i" << endl;
}

void Complex::subtraction(double realPartNum, double imaginaryPartNum)
{
    cout << realPart - realPartNum << " " << imaginaryPart - imaginaryPartNum << "i" << endl;
}

void Complex::printComplex()
{
    cout << realPart << " " << imaginaryPart << "i" << endl;
}