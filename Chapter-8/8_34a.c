#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STR_SIZE 1000

void getCharsCount(const char*, char*, char*);
void printResult(const char*, const char*);

int main(void) {
	char str[STR_SIZE + 1 ];
	char lowerCahrCount[26] = { 0 };
	char upperCahrCount[26] = { 0 };

	//To be, or not to be: that is the question:
	printf("Enter strings, max char size = %d\n", STR_SIZE);
	gets_s(str, STR_SIZE);
	printf("You enter - %s\n", str);
	getCharsCount(str, lowerCahrCount, upperCahrCount);
	printResult(lowerCahrCount, upperCahrCount);
	return 0;
}

void printResult(const char* lowerCahrCount, const char* upperCahrCount) {
	puts("\nPrint result:");
	for (int e = 0; e < 26; e++) {
		printf("%c = %d ", e + 97, lowerCahrCount[e]);
		printf("%c = %d\n", e + 65, upperCahrCount[e]);
	}
	puts("\nFinish.");
}

void getCharsCount(const char* strPrt, char* lowerCahrCountPtr, char* upperCahrCountPtr) {
	//65-90 upper 97-122 lower
	//Check size strlen in gets_s in main! 
	int strSize = strlen(strPrt);
	for (int i = 0; i < strSize; i++) {
		if (islower(strPrt[i]))
			++lowerCahrCountPtr[strPrt[i] - 97];
		else if (isupper(strPrt[i]))
			++upperCahrCountPtr[strPrt[i] - 65];
		else
			continue;
	}
}