#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	int t[2][5];
	int minVal;
	int sum4elem = 0;

	for (int e = 0; e < 2; e++) {
		for (int i = 0; i < 5; i++) {
			//scanf_s("%d\n", &t[e][i]);
			t[e][i] = 2 + rand() % 8;
		}
	}

	puts("");
	for (int e = 0; e < 2; e++) {
		for (int i = 0; i < 5; i++) {
			printf(" %d %d = %d\n",e, i, t[e][i]);
		}
	}
	puts("");
	minVal = t[0][0];
	for (int e = 0; e < 2; e++) {
		for (int i = 0; i < 5; i++) {
			if (minVal > t[e][i]) {
				minVal = t[e][i];
			 }
		}
	}
	puts("");
	printf(" MinVal = %d", minVal);

	puts("");
	for (int i = 0; i < 5; i++) {
		printf("%d ", t[1][i]);
	}

	puts("");
	for (int e = 0; e < 2; e++) {
		sum4elem += t[e][3];
	}
	printf("Sum 4 table = %d ", sum4elem);
	puts("");
	puts("");
	printf("    ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", i);
	}
	puts("");
	for (int e = 0; e < 2; e++) {
		printf("%d   ",e);
		for (int i = 0; i < 5; i++) {
			printf("%d ",t[e][i]);
		}
		puts("");
	}

	return 0;
}