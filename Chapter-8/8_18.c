#include<stdio.h>
#include<string.h>


int main(void) {
	int count = 0;
	char* searchPtr;
	char strFirstText[100];
	char strSecondText[100];
	char charFind;
	puts("Enter string first text:");
	gets_s(strFirstText);
	puts("Enter string second text:");
	gets_s(strSecondText);
	puts("Enter text for find:");
	charFind = getchar();
	puts("Result:");

	searchPtr = strchr(strFirstText, charFind);
	while (searchPtr != NULL) {
		count++;
		searchPtr = strchr(searchPtr + 1, charFind);
	}

	searchPtr = strchr(strSecondText, charFind);
	while (searchPtr != NULL) {
		count++;
		searchPtr = strchr(searchPtr + 1, charFind);
	}

	printf("Finded %d\n", count);
	return 0;
}
