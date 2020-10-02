#include<stdio.h>
#include<string.h>
#define MAX_STR_SIZE 100


void printLatinWord(char*);

int main(void) {
	char str[MAX_STR_SIZE] = {};
	char* tokenPtr;
	puts("Enter text:");
	gets_s(str);
	puts("\nResult:");
	char* nextToken = NULL;
	tokenPtr = strtok_s(str, " ", &nextToken);
	while (tokenPtr != NULL) {
		printLatinWord(tokenPtr);
		tokenPtr = strtok_s(NULL, " ", &nextToken);
	}
	return 0;
}

void printLatinWord(char* tokenStr) {
	char tempStr[MAX_STR_SIZE];
	int size = 0;;
	for (size = 0; tokenStr[size] != '\0'; size++)
		tempStr[size] = tokenStr[size + 1];

	printf("size = %d\n", size);

	tempStr[size - 1] = tokenStr[0];
	tempStr[size] = '\0';
	strcat_s(tempStr, MAX_STR_SIZE, "ay");
	puts(tempStr);
}