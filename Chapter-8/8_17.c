#include<stdio.h>
#include<string.h>


int main(void) {
	int count = 0;
	char* searchPtr;
	char strFirstText[100];
	char strSecondText[100];
	char strFind[30];
	puts("Enter string first text:");
	gets_s(strFirstText);
	puts("Enter string second text:");
	gets_s(strSecondText);
	puts("Enter text for find:");
	gets_s(strFind);
	puts("Result:");

	searchPtr = strstr(strFirstText, strFind);
	while (searchPtr != NULL) {
		count++;
		searchPtr = strstr(searchPtr + 1, strFind);
	}

	searchPtr = strstr(strSecondText, strFind);
	while (searchPtr != NULL) {
		count++;
		searchPtr = strstr(searchPtr + 1, strFind);
	}

	printf("Finded %d\n", count);
	return 0;
}
