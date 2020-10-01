#include <stdio.h>
#include <ctype.h>

void printStrToUpper(char[]);
void printStrToLower(char[]);

int main(void) {
	char str[100];
	puts("Enter string:");
	gets_s(str);
	printStrToUpper(str);
	printf("String upper - %s\n", str);
	printStrToLower(str);
	printf("String lower - %s\n", str);
	return 0;
}

void printStrToUpper(char str[]) {
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);
}

void printStrToLower(char str[]) {
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
}