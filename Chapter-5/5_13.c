#include <stdio.h>
//for test #include <limits.h>
#include <stdlib.h>


int main() {
	printf("%.0d\n", 1 + rand() % 2);
	printf("%.0d\n", 1 + rand() % 100);
	printf("%.0d\n", rand() % 10);
	printf("%d\n", rand() % 113 + 1000);
	printf("%d\n", rand() % 1 - 1);
	printf("%d\n", rand() % 15 - 3);

	// Test
	//for (unsigned int i = 0, c; i <= INT_MAX; i++) {
	//	c = i % 15 - 3;
	//	if (-3 < c & c < 11) {
	//		printf("%d\n", i);
	//	}
	//}

	return 0;
}