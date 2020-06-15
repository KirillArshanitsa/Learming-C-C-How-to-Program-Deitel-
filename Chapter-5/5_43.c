#include<stdio.h>


int main(void) {
	static int count = 1;
	printf("Value is %d\n", --count);
	main();
	return 0;
}

