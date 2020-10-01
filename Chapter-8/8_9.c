#include<stdio.h>
#include<string.h>

int main(void) {
	int comparResult;
	char str1[100];
	char str2[100];
	puts("Enter first string:");
	gets_s(str1);
	puts("Enter second string:");
	gets_s(str2);
	printf("Comparing %s and %s\n", str1, str2);
	comparResult = strcmp(str1, str2);
	switch (comparResult)
	{
	case 0:
		puts("Stings equal.");
		break;
	case 1:
		printf("String %s more than %s\n", str1, str2);
		break;
	case -1:
		printf("String %s less than %s\n", str1, str2);
		break;
	default:
		printf("Error - balues %d is not support \n", comparResult);
		break;
	}

	return 0;
}