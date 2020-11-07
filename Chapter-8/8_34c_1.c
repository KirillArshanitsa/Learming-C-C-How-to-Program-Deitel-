#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 100000

void parseString(char*);

int main(void) {
	char str[MAX_STR_SIZE];
	printf("%s %lu\n","Enter string max size - ", MAX_STR_SIZE);
	gets_s(str, MAX_STR_SIZE);
	
	//To be, or not to be: that is the question:
	printf("You enter - %s\n", str);
	parseString(str);

	return 0;
}

void parseString(char* str) {
	puts("\nResults:");
	size_t strCount = 0;
	char *tpkenTmpPtr = NULL;
	char *tmpPtr;
	char* tokenPtr = strtok_s(str, " ", &tpkenTmpPtr);

	while (tokenPtr != NULL) {
		++strCount;
		tmpPtr = strstr(tokenPtr + strlen(tokenPtr) + 1, tokenPtr);
		while (tmpPtr != NULL) {
			tmpPtr = strstr(tmpPtr + strlen(tokenPtr) + 1, tokenPtr);
			strCount++;
		}
		printf("%s\"%s\" = %zd\n","Count of word ", tokenPtr, strCount);

		tmpPtr = NULL;
		strCount = 0;
		tokenPtr = strtok_s(NULL , " ", &tpkenTmpPtr);
	}
	puts("\nFinish.");
}