#include <stdio.h>
#include <stdlib.h>


int throwTwoDice(void);

int throwTwoDice(void) {
	return (1 + rand() % 6) + (1 + rand() % 6);
}

int main(void) {

	int throwResults[13] = { 0 }; //[2-12]
	unsigned int throwsCount =  36000;
	printf("Throws count %u\n", throwsCount);

	for (int count = 0; count < throwsCount; count++) {
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
	for (int e = 2, i = 0; e < 13; e++) {
		if (e < 8)
			printf("%5s ", ((int)(((double)throwResults[e] / 1000) + 0.5) / (++i) ? "True" : "False"));
		else
			printf("%5s ", ((int)(((double)throwResults[e] / 1000) + 0.5) / (--i) ? "True" : "False"));
	}
	puts("");
	return 0;
}