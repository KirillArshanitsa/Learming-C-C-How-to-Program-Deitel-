#include <stdio.h>
#include <stdlib.h>


int throwTwoDice(void);

int throwTwoDice(void) {
	return (1 + rand() % 6) + (1 + rand() % 6);
}

int main(void) {
	int throwResults[13] = {0};
	int throwsCount = 36000;

	for (int count = 0 ; count < throwsCount; count++) {
		++throwResults[throwTwoDice()];
	}
	for (int e = 2; e < 13; e++) {
		printf("%5d ", e);
	}
	puts("");
	for (int e = 2; e < 13; e++) {
		printf("%5d ", throwResults[e]);
	}
	puts("");
	puts("");

	for (int e = 2; e < 13; e++) {
		//printf("%5.0f ", (double)throwResults[e] / 1000);
		printf("%5d ", (int)(((double)throwResults[e] / 1000) + 0.5));
	}

	return 0;
}