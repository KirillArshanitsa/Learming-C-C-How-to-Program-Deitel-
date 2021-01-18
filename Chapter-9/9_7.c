#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	_set_printf_count_output(1);

	int number[10];
	unsigned int totalCount = 0;
	unsigned int currentCount;
	for (int i = 0; i < 10; i++)
		number[i] = 1 + rand() % 1000;
	printf("Value\tTotal characters\n");
	for (int i = 0; i < 10; i++) {
		printf("%-d%n", number[i], &currentCount);
		printf("\t%-d\n", totalCount += currentCount);
	}
}