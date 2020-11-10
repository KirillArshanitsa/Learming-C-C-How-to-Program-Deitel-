#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_SIZE 100000

void parseString(char*);
void clearString(char*);

int main(void) {
	char str[MAX_STR_SIZE];
	printf("%s %lu\n", "Enter string max size - ", MAX_STR_SIZE);
	gets_s(str, MAX_STR_SIZE);

	//To be, or not to be: that is the question: bethat:
	printf("You enter - %s\n", str);
	clearString(str);
	parseString(str);

	return 0;
}

void clearString(char* str) {
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (isalnum(str[i]) == 0)
			str[i] = ' ';
	}
}

void parseString(char* str) {
	puts("\nResults:");
	size_t strCount = 0;
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

		printf("%s\"%s\" = %zd\n", "Count of word ", tokenPtr, strCount);

		tmpPtr = NULL;
		strCount = 0;
		tokenPtr = strtok_s(NULL, " ", &tokenTmpPtr);
	}
	puts("\nFinish.");
}