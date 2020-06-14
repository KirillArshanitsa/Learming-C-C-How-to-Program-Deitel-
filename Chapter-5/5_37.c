#include <stdio.h>
unsigned int power(unsigned int, unsigned int);

unsigned int power(unsigned int base, unsigned int exponenet) {
	if (exponenet == 1)
		return base;
	else
		return base * power(base, --exponenet);
}

int main(void) {
	printf("Result is %u", power(2, 3));
	return 0;
}