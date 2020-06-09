#include <stdio.h>
#include <math.h>

double roundToInteger(double);
double roundToTenths(double);
double roundToHoundrerths(double);
double roundToThousandths(double);

double roundToInteger(double num) {
	return (floor(num + .5));
}

double roundToTenths(double num) {
	return (floor(num *10 + .5) / 10);
}

double roundToHoundrerths(double num) {
	return (floor(num * 100 + .5) / 100);
}

double roundToThousandths(double num) {
	return (floor(num * 1000 + .5) / 1000);
}

int main() {
	double x;
	puts("Enter nuber");
	scanf_s("%lf", &x);
	printf("You enter %.2f\n roundToInteger = %.2f, roundToTenths = %.2f, roundToHoundrerths = %.2f, roundToThousandths = %.3f\n", 
		x, roundToInteger(x), roundToTenths(x), roundToHoundrerths(x), roundToThousandths(x));
	return 0;
}