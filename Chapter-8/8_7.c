#include<stdio.h>

int main(void) {
	int count = 4;
	int num;
	int result = 0;

	while (count--) {
		char str[80];
		puts("Enter numbers:");
		gets_s(str);
		sscanf_s(str, "%d", &num);
		result += num;
	}
	printf("\nResult = %d\n", result);
	return 0;
}