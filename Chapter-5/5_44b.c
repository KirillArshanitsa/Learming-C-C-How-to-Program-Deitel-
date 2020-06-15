#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkMultiplicationTable(int, int, int, int);

void checkMultiplicationTable(int num1, int num2, int stepen, int operation) {
	int yourResponse, localOperation, operationResult;
	static unsigned int sucessCount;
	static unsigned int failCount;

	if (sucessCount + failCount >= 10) {
		if (sucessCount * 10 < 75) //0.1 * sucessCount * 100
			printf("\nPlease ask your teacher additional classes!!\n");
		return;
	}

	localOperation = operation;
	if (localOperation == 5)
		localOperation = 1 + rand() % 5;

	switch (localOperation) {
	case 1:
		printf("How much is %d + %d ?\n", num1, num2);
		scanf_s("%d", &yourResponse);
		operationResult = num1 + num2;
		break;
	case 2:
		printf("How much is %d - %d ?\n", num1, num2);
		scanf_s("%d", &yourResponse);
		operationResult = num1 - num2;
		break;
	case 3:
		printf("How much is %d * %d ?\n", num1, num2);
		scanf_s("%d", &yourResponse);
		operationResult = num1 * num2;
		break;
	case 4:
		printf("How much is %d / %d ?\n", num1, num2);
		scanf_s("%d", &yourResponse);
		operationResult = num1 * num2;
		break;
	}
	if (operationResult == yourResponse) {
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
		num1 = 1 * stepen + rand() % (9 * stepen);
		num2 = 1 * stepen + rand() % (9 * stepen);
		checkMultiplicationTable(num1, num2, stepen, operation);
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
		checkMultiplicationTable(num1, num2, stepen, localOperation);
	}
}

int main(void) {
	int level, operation, levelVal = 1, firstNum, secondNum;
	puts("Please choise level of difficulty 1,2 ... and operation: 1 for +, 2 for - , 3 for *, 4 for /, 5 for any.");
	scanf_s("%d %d", &level, &operation);
	while(--level)
		levelVal *= 10;
	srand(time(NULL));
	firstNum = 1 * levelVal + rand() % (9 * levelVal);
	secondNum = 1 * levelVal + rand() % (9 * levelVal);
	checkMultiplicationTable(firstNum, secondNum, levelVal, operation);

	return 0;
}