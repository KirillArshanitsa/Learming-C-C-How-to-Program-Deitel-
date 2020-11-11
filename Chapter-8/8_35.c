#include <stdio.h>
#include <string.h>

#define STRING_SIZE 1000
#define FIELD_SIZE 10
#define INDENT_SIZE 60

void formatString(const char *);
void printString(char*, int);

int main(void) 
{
	char str[STRING_SIZE]; //"Chek my funct strncpy(endFieldStr, beginFieldStr, FIELD_SIZE - 1);strncpy_s(strCopyPtr, buferCopyStrSize, beginFieldStr, FIELD_SIZE);strPtr += INDENT_SIZE;";
	puts("Enter string:");
	gets_s(str, STRING_SIZE);

	puts("Original string:");
	puts(str);
	puts("\nResult:");
	formatString(str);
	return 0;
}


void formatString(const char *strPtr)
{	
	char beginFieldStr[FIELD_SIZE];
	char endFieldStr[FIELD_SIZE];
	char strCopy[STRING_SIZE];
	char *strCopyPtr = strCopy;

	size_t strSize =  strlen(strPtr);
	size_t copyStrSize = 0;
	size_t buferCopyStrSize = STRING_SIZE;
	unsigned long int sizeOfCoptStr = ((strSize / INDENT_SIZE) * (2 * FIELD_SIZE)) + strSize;

	//Check size of copy string,
	//printf("max size = %lu str = %zu\n", sizeOfCoptStr, strSize);
	if (STRING_SIZE < sizeOfCoptStr) {
		printf("Error - you enter too much string, max size = %lu\n", sizeOfCoptStr);
		return;
	}

	for (int i = 0; i < FIELD_SIZE; i++)
		beginFieldStr[i] = ' ';
	strncpy_s(endFieldStr ,beginFieldStr, FIELD_SIZE -1);
	endFieldStr[FIELD_SIZE - 1] = '\n';


	while (strSize >= copyStrSize){
		strncpy_s(strCopyPtr, buferCopyStrSize, beginFieldStr, FIELD_SIZE);
		strCopyPtr += FIELD_SIZE;
		buferCopyStrSize -= FIELD_SIZE;

		if (INDENT_SIZE > strlen(strPtr)) {
			strncpy_s(strCopyPtr, buferCopyStrSize, strPtr, strlen(strPtr));
			strCopyPtr += strlen(strPtr);
			buferCopyStrSize -= strlen(strPtr);
			strPtr += strlen(strPtr);
		}
		else {
			strncpy_s(strCopyPtr, buferCopyStrSize, strPtr, INDENT_SIZE);
			strPtr += INDENT_SIZE;
			strCopyPtr += INDENT_SIZE;
			buferCopyStrSize -= INDENT_SIZE;
		}

		strncpy_s(strCopyPtr, buferCopyStrSize, endFieldStr, FIELD_SIZE);
		strCopyPtr += FIELD_SIZE;
		buferCopyStrSize -= FIELD_SIZE;
		copyStrSize += INDENT_SIZE;
	}

	puts(strCopy);
}