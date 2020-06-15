#include<stdio.h>
#include<stdlib.h>

int gcd(int, int);

int main(void) {
	for (int i = 1 ,num = rand(); i <= 100; i++, num = rand())
		printf("%d and %d, result = %d\n", num, i, gcd(num, i ));
	return 0;
}

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}