#include<stdio.h>

int main(void) {
	int count = 4;
	double num;
	double result = 0;

	while (count--) {
		char str[80];
		puts("Enter numbers:");
		gets_s(str);
		sscanf_s(str, "%lf", &num);
		result += num * 2;
	}
	printf("\nResult = %lf\n", result);
	return 0;
}