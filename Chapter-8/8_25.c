#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM_CHAR 127

//void printCharFromASCII(void);
void generateCode(void);

int main(void) {
	generateCode();
	//printCharFromASCII();
	return 0;
}

void generateCode(void) {
	puts("Start:");
	for (int i = 0; i <= 255; i++) {
		printf("%d) %c\n",i, i);
	}
	puts("\n Finish.");
}

void printCharFromASCII(void) {
	char enteredASCII[4]; // 4 - max num in ASCII = 3, + 1 for /0
	unsigned int numASCII;
	puts("Enter EOF for finish.");
	while (1) {
		puts("Enter ASCII code:");
		gets_s(enteredASCII, 4);
		numASCII = atoi(enteredASCII);
		if (numASCII > MAX_NUM_CHAR)
			printf("Error, you enter %u, max nym is %d\n", numASCII, MAX_NUM_CHAR);
		//printf("%d\n", numASCII);
		putchar(numASCII);
		puts("");
	}
}
