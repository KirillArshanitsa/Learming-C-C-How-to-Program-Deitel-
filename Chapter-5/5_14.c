#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int num = 1 + rand() % 10;
	printf("%d\n", num % 2 ? ++num: num);
	num = 3 + rand() % 9;
	printf("%d\n", num % 2 ? num : ++num);
	num = 6 + rand() % 17;
	printf("%d\n", num % 2 ? ++num : num);

	//Test
	//for ( int i = 0, c; i <= 22; i++) {
	//	int num = 6 + i % 17;
	//	printf("%d\n", num % 2 ? ++num : num);
	//}

	return 0;
}