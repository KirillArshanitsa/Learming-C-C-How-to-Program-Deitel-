#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define NUMBER_COUNT 8

void printStr(const char*);

int main(void)
{
	char printNum[NUMBER_COUNT + 1];
	puts("Enter $:");
	gets_s(printNum);
	puts("\nResult");
	printStr(printNum);
	return 0;
}

void printStr(const char *numStrPtr)
{
	size_t printNumSize = NUMBER_COUNT - strlen(numStrPtr);
	while (printNumSize-- > 0)
		printf("*");
	for (size_t i = 0; numStrPtr[i] != '\0'; i++) {
		if ((isdigit(numStrPtr[i]) == 0) && (numStrPtr[i] != '.') && (numStrPtr[i] != ',')) {
			printf_s("\nError in %zu %c\n", i, numStrPtr[i]);
			return;
		}
		else 
			printf_s("%c", numStrPtr[i]);
		
	}

}