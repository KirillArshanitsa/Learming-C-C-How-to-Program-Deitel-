#include<stdio.h>
#define STR_SIZE 50
#define STR_COUNT 2


void getStr(const char const*[],  const char);

int main(void) {
	const char findedChar = 'b';
	const char* strArrayPtr[STR_COUNT];
	printf("Find string begin %c\n", findedChar);
	getStr(strArrayPtr, findedChar);
	return 0;
}

void getStr(const char const* strArrayPtr[], const char findedChar) {
	static unsigned int strCount = STR_COUNT;

	if (0 == strCount) {
		puts("\nResults:");
		return;
	}

	char tmpStr[STR_SIZE];
	puts("Enter string:");
	gets_s(tmpStr, STR_SIZE);
	--strCount;

	getStr(strArrayPtr, findedChar);

	if (findedChar == tmpStr[0])
		puts(tmpStr);

}