#include<stdio.h>
#include<string.h>


int main(void) {
	char* searchPtr;
	char strText[100];
	char strFind[30];
	puts("Enter string text:");
	gets_s(strText);
	puts("Enter text for find:");
	gets_s(strFind);
	puts("Result:");
	searchPtr = strstr(strText, strFind);
	while (searchPtr != NULL) {
		puts(searchPtr);
		searchPtr = strstr(searchPtr + 1, strFind);
	}
	return 0;
}
