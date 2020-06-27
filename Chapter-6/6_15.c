#include <stdio.h>
#define tryCount 20

int main(void) {
	int currentNum;
	int containsNum;
	int count = 0;
	int arrayNum[tryCount] = { 0 };

	do {
		puts("Enter number 20 - 100:");
		scanf_s("%d", &currentNum);
		if (currentNum < 20 || currentNum > 100) {
			printf("Enter number 20 - 100, you enter = %d\n", currentNum);
			continue;
		}

		containsNum = 0;
		arrayNum[count] = currentNum;
		for (int e = 0; e < count; e++) {
			if (arrayNum[e] == currentNum) {
				containsNum = 1;
				break;
			}
		}
		if(!containsNum)
			printf("You enter diferent num %d\n", currentNum);

		++count;
	} while (count < tryCount);


	return 0;
}