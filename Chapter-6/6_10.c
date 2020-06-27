#include <stdio.h>
#define SELLERS_RANGE 9
#define SELLERS_COUNT 5
#define BEGINRANGESAL 300
#define STEPOFRANGESAL 99
#define MAXOFRANGESAL 1000

void printArray(int a[]);

void printArray(int a[]) {
	for (int e = 0; e < SELLERS_RANGE ;e++) {
		printf("Count of range %d = %d\n", e + 1 , a[e]);
	}
}
int main() {
	int rangeOfSalary[SELLERS_RANGE] = {0};
	int sellersCount = SELLERS_COUNT;
	int enteredSalary;

	while (sellersCount > 0) {
		puts("Plase enter the salary of seller:");
		scanf_s("%d", &enteredSalary);
		if (enteredSalary < BEGINRANGESAL - STEPOFRANGESAL) {
			printf("!!!Plase enter the salary of seller begin %d, you enter %d !!!\n", BEGINRANGESAL - STEPOFRANGESAL, enteredSalary);
			continue;
		}
	
		if (BEGINRANGESAL - STEPOFRANGESAL <= enteredSalary && enteredSalary <= BEGINRANGESAL - 1) {
			++rangeOfSalary[0];
		}
		else {
			if (enteredSalary >= MAXOFRANGESAL) {
				++rangeOfSalary[SELLERS_RANGE - 1];
			}
			for (int i = BEGINRANGESAL, e = 1; i <= MAXOFRANGESAL; i = i + STEPOFRANGESAL + 1, e++) {
				if (i <= enteredSalary && enteredSalary <= i + STEPOFRANGESAL) {
					++rangeOfSalary[e];
					break;
				}
			}
		}
		sellersCount--;
	}
	printArray(rangeOfSalary);

	return 0;
}