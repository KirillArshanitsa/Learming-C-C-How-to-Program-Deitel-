#ifndef CLASS_H
#define CLASS_H
class Complex {
public:
    Complex(double = 0, double = 0);
    void sum(double, double);
    void subtraction(double, double);
    void printComplex();
private:
    double realPart;
    double imaginaryPart;
};
#endif