#include<stdio.h>

size_t myStrlen(const char*);
size_t myStrlenPtr(const char*);

int main(void) {
	char myStr[] = "MyString";
	printf("Size %s = %zd\n", myStr, myStrlen(myStr));
	printf("Size with Ptr%s = %zd\n", myStr, myStrlenPtr(myStr));
	return 0;
}

size_t myStrlen(const char* str) {
	size_t strLen = 0;
	while (str[++strLen] != '\0')
		;

	return strLen;
}

size_t myStrlenPtr(const char* str) {
	size_t strLen = 0;
	while (*(str++) != '\0' )
		++strLen;

	return strLen;
}