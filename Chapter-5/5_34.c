#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkMultiplicationTable(int, int);

void checkMultiplicationTable(int num1, int num2) {
	int yourResponse;
	static unsigned int sucessCount;
	static unsigned int failCount;

	if (sucessCount + failCount >= 10) {
		if (sucessCount * 10 < 75) //0.1 * sucessCount * 100
			printf("\nPlease ask your teacher additional classes!!\n");
		return;
	}

	printf("How much is %d times %d ?\n", num1, num2);
	scanf_s("%d", &yourResponse);
	if (num1 * num2 == yourResponse) {
		++sucessCount;
		switch (1 + rand() % 4) {
			case 1:
				printf("Very good.\n");
				break;
			case 2:
				printf("Excelent!\n");
				break;
			case 3:
				printf("Nice work!.\n");
				break;
			case 4:
				printf("Keep up the good work.\n");
				break;
		}
		checkMultiplicationTable(rand() % 10, rand() % 10);
	}
	else {
		++failCount;
		switch (1 + rand() % 4) {
			case 1:
				printf("No. Please try again.\n");
				break;
			case 2:
				printf("Wrong. Try once more\n");
				break;
			case 3:
				printf("Don't give up!.\n");
				break;
			case 4:
				printf("No. keep trying.\n");
				break;
			}
		checkMultiplicationTable(num1, num2);
	}
}

int main(void) {
	srand(time(NULL));
	checkMultiplicationTable(rand() % 10, rand() % 10);
	return 0;
}