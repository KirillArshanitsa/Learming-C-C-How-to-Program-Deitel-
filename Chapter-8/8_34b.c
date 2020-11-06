#include <stdio.h>
#include <string.h>

#define STR_SIZE 100000

long int getWordCount(char*, size_t*);
void printResult(const size_t*, unsigned long int);

int main(void) {
	char str[STR_SIZE + 1];
	size_t wordCount[STR_SIZE + 1] = {0};

	//Whether 'tis nobles in the mind to suffer
	printf("Enter strings, max char size = %d\n", STR_SIZE);
	gets_s(str, STR_SIZE);
	printf("You enter - %s\n", str);

	printResult(wordCount, getWordCount(str, wordCount));
	return 0;
}

void printResult(const size_t *wordCountPtr, unsigned long int size) {
	puts("\nPrint result:");
	printf("%s%12s\n", "Word length", "Words count");
	for (unsigned long int  e = 1; e < size; e++) {
		printf("%lu%12zu\n", e, wordCountPtr[e]);
	}
	puts("\nFinish.");
}

long int getWordCount(char *strPrt, size_t *wordCountPtr) {
	unsigned long int wordCountResult = 0;
	char* next_token = NULL;	
	char* tokenPtr = strtok_s(strPrt, " ", &next_token);
	while (tokenPtr != NULL) {
		++wordCountPtr[strlen(tokenPtr)];
		++wordCountResult;
		tokenPtr = strtok_s(NULL, " ", &next_token);
	}
	return wordCountResult;
}