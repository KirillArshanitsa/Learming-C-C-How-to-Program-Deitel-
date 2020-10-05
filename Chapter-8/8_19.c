#include<stdio.h>
#include<string.h>

void findLetterCount(const char[], int[]);
void printLetterCount(const int[]);

int main(void) {

	char strFirstText[100];
	char strSecondText[100];
	int letterCount[26] = {0}; //65-90 A-Z char count in A[0] Z[24] 97-122 a-z

	puts("Enter string first text:");
	gets_s(strFirstText);
	puts("Enter string second text:");
	gets_s(strSecondText);
	puts("\nResult:");

	findLetterCount(strFirstText, letterCount);
	findLetterCount(strSecondText, letterCount);
	printLetterCount(letterCount);
	return 0;
}

void findLetterCount(const char str[], int letterCount[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		for (int charLetter = 65; charLetter <= 90; charLetter++) {
			if ((str[i] == charLetter) || (str[i] == charLetter + 32)){// +32 - to lower case char
				++letterCount[charLetter - 65];
				break;
			}
		}
	}
}

void printLetterCount(const int letterCount[]) {
	puts("Finded letters count:");
	for (int charLetter = 65; charLetter <= 90; charLetter++) {
		printf("%3c", charLetter);
	}
	puts("");
	for (int charLetter = 0; charLetter <= 25; charLetter++) {
		printf("%3d", letterCount[charLetter]);
	}
	puts("");
}