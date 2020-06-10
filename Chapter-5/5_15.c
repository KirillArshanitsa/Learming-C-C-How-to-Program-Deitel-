#include <stdio.h>

double hypotenuse(double, double);

double hypotenuse(double sideA, double sideB) {
	return sideA * sideA + sideB * sideB;
}

int main() {
	double sideA, sideB;
	puts("Enter sideA and sideB");
	scanf_s("%lf %lf", &sideA, &sideB);
	printf("Hypotenuse is %.2f", hypotenuse(sideA, sideB));
	return 0;
}