#include <stdio.h>

int fibonacci(int);

int fibonacci(int n) {
	if (n < 2)
		return n;
	int fib = 0;
	for (int firstNum = 0, secondNum = 1, i = 1; n != i ; i++) {
		fib = firstNum + secondNum;
		firstNum = secondNum;
		secondNum = fib;
	}
	return fib;
}

int main(void) {
	printf("Result is %d", fibonacci(6));
	return 0;
}