#include <stdio.h>
#include <string.h>

#define STR_MAX_SIZE 100

int main(void)
{
	char str[STR_MAX_SIZE];

	unsigned int strSize;
	puts("Enter string");
	gets_s(str);
	strSize = strlen(str);
	printf("%*s", strSize * 2, str);
}