#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 100000

void parseString(char*);

int main(void) {
	char str[MAX_STR_SIZE];
	printf("%s %lu\n", "Enter string max size - ", MAX_STR_SIZE);
	gets_s(str, MAX_STR_SIZE);

	//To be, or not to be: that is the question:
	printf("You enter - %s\n", str);
	parseString(str);

	return 0;
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
			if (previousTempPtr[tokenStrSize] == ' ') {
				for (size_t clearStrPtr = 0; clearStrPtr < tokenStrSize; clearStrPtr++)
					previousTempPtr[clearStrPtr] = ' ';
			}
			else if (previousTempPtr[tokenStrSize] == '\0') {
				for (size_t clearStrPtr = 0; clearStrPtr < tokenStrSize; clearStrPtr++)
					previousTempPtr[clearStrPtr] = ' ';
			}
			strCount++;
		}
		printf("%s\"%s\" = %zd\n", "Count of word ", tokenPtr, strCount);

		tmpPtr = NULL;
		strCount = 0;
		tokenPtr = strtok_s(NULL, " ", &tokenTmpPtr);
	}
	puts("\nFinish.");
}