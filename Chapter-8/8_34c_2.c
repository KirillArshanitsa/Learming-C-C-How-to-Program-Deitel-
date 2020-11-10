#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_SIZE 900

size_t parseString(char*, char* [], size_t[]);
void printResult(char* const [], const size_t[], const size_t);
void sortResult(char* [], size_t[], const size_t);
void clearString(char*);

int main(void)
{
	char str[MAX_STR_SIZE];
	char* allStringPtr[MAX_STR_SIZE];
	size_t allStringCountPtr[MAX_STR_SIZE];
	printf("%s %lu\n", "Enter string max size - ", MAX_STR_SIZE);
	gets_s(str, MAX_STR_SIZE);

	//To be, or not to be: that is the question: bethats";
	printf("You enter - %s\n", str);
	clearString(str);
	size_t strCount = parseString(str, allStringPtr, allStringCountPtr);
	sortResult(allStringPtr, allStringCountPtr, strCount);
	printResult(allStringPtr, allStringCountPtr, strCount);

	return 0;
}

void clearString(char* str) {
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (isalnum(str[i]) == 0)
			str[i] = ' ';
	}
}

void sortResult(char* allStringPtr[], size_t allStringCountPtr[], const size_t allStrCount)
{
	size_t tmpCount;
	char* tmpChar;
	for (size_t e = 0; e < allStrCount - 1; e++) {
		for (size_t i = 1; i < allStrCount - 1; i++) {
			if (allStringPtr[i][0] > allStringPtr[i + 1][0]) {
				tmpChar = allStringPtr[i];
				allStringPtr[i] = allStringPtr[i + 1];
				allStringPtr[i + 1] = tmpChar;
				tmpCount = allStringCountPtr[i];
				allStringCountPtr[i] = allStringCountPtr[i + 1];
				allStringCountPtr[i + 1] = tmpCount;
			}
		}
	}
}

void printResult(char* const allStringPtr[], const size_t allStringCountPtr[], const size_t allStrCount)
{
	puts("\nResults:");
	for (size_t i = 0; i < allStrCount; i++) {
		printf("%s\"%s\" = %zd\n", "Count of word ", allStringPtr[i], allStringCountPtr[i]);
	}
	puts("\nFinish.");
}

size_t parseString(char* str, char* allStringPtr[], size_t allStringCountPtr[])
{
	size_t strCount = 0;
	size_t allStrCount = 0;
	size_t tokenStrSize;
	char* tokenTmpPtr = NULL;
	char* tmpPtr;
	char* previousTempPtr;

	char* tokenPtr = strtok_s(str, " ", &tokenTmpPtr);
	while (tokenPtr != NULL) {
		++strCount;
		tokenStrSize = strlen(tokenPtr);
		tmpPtr = strstr(tokenPtr + tokenStrSize + 1, tokenPtr);
		//delete equals string
		while (tmpPtr != NULL) {
			previousTempPtr = tmpPtr;
			tmpPtr = strstr(tmpPtr + tokenStrSize + 1, tokenPtr);
			//check delimiter if part of word and finish string 
			if ((*(previousTempPtr - 1) == ' ') && (previousTempPtr[tokenStrSize] == ' ')) {
				for (size_t clearStrPtr = 0; clearStrPtr < tokenStrSize; clearStrPtr++)  // tokenStrSize+ 1
					previousTempPtr[clearStrPtr] = ' ';
				strCount++;
			}
			else if ((*(previousTempPtr - 1) == ' ') && (previousTempPtr[tokenStrSize] == '\0')) {
				for (size_t clearStrPtr = 0; clearStrPtr < tokenStrSize; clearStrPtr++)
					previousTempPtr[clearStrPtr] = ' ';
				strCount++;
			}
		}

		allStringPtr[allStrCount] = tokenPtr;
		allStringCountPtr[allStrCount] = strCount;
		++allStrCount;
		tmpPtr = NULL;
		strCount = 0;
		tokenPtr = strtok_s(NULL, " ", &tokenTmpPtr);
	}

	return allStrCount;
}