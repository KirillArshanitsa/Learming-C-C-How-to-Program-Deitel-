#include<stdio.h>
#include<string.h>

#define STR_SIZE 50
#define STR_COUNT 2


void getStr(const char const*[],  const char[]);

int main(void) {
	const char findedStr[] = "ED";
	const char* strArrayPtr[STR_COUNT];
	printf("Find string ending %s\n", findedStr);
	getStr(strArrayPtr, findedStr);
	return 0;
}

void getStr(const char const* strArrayPtr[], const char findedStr[]) {
	static unsigned int strCount = STR_COUNT;

	if (0 == strCount) {
		puts("\nResults:");
		return;
	}
	unsigned int strSize;
	char tmpStr[STR_SIZE];
	puts("Enter string:");
	gets_s(tmpStr, STR_SIZE);
	--strCount;
	strSize = strlen(tmpStr);
	getStr(strArrayPtr, findedStr);

	//TODO change it
	if (strSize < 2)
		return;
	if ((findedStr[0] == tmpStr[strSize - 2]) && (findedStr[1] == tmpStr[strSize - 1]))
		puts(tmpStr);

}