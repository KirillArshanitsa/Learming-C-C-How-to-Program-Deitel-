#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkMultiplicationTable(int, int);

void checkMultiplicationTable(int num1, int num2) {
	int yourResponse;
	printf("How much is %d times %d ?\n", num1, num2);
	scanf_s("%d", &yourResponse);
	if (num1 * num2 == yourResponse) {
		printf("Very well.\n");
		checkMultiplicationTable(rand() % 10, rand() % 10);
	}
	else {
		printf("Not correct, please try again.\n");
		checkMultiplicationTable(num1, num2);
	}
}

int main(void) {
	srand(time(NULL));
	checkMultiplicationTable(rand() % 10, rand() % 10);
	return 0;
}