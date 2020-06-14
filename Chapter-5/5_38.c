#include <stdio.h>

double fibonacci(double);

 double fibonacci(double n) {
	double fib = 0;
	for (double firstNum = 0, secondNum = 1, i = 0 ; ; i++ ) { // ; n != i;
		fib = firstNum + secondNum;
		printf("fib is %f ", fib);
		firstNum = secondNum;
		secondNum = fib;
	}
	return fib;
}

int main(void) {
	printf("Result is %", fibonacci(4));
	return 0;
}