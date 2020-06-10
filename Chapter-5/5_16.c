#include <stdio.h>

int integerPower(int, int);

int integerPower(int base, int exponent) {
	int result = 1 ;
	for (; exponent > 0; exponent--)
		result *= base;
	return result;
}

int main() {
	int base, exponent;
	puts("Enter base and exponent");
	scanf_s("%d %d", &base, &exponent);
	printf("Base is %d , Exponent is %d Result is %d", base, exponent, integerPower(base, exponent));
	return 0;
}