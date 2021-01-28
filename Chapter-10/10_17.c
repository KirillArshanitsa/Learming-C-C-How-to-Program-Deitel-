#include <stdio.h>

void printBitNum(unsigned );
void reverseBits(unsigned );

int main(void)
{
	unsigned num;
	
	puts("Enter number:");
	scanf_s("%u", &num);
	puts("Origin num:");
	printBitNum(num);
	puts("\nRevert num:");
	reverseBits(num);
	return 0;
}

void reverseBits(unsigned num)
{
	//printBitNum(~num);
	unsigned int n = 1;
	n <<= 31;
	for (int i = 1; i < 33; i++) {
		printf("%d", num & n ? 0 : 1);
		num <<= 1;
		if (i % 8)
			;
		else
			printf(" ");
	}

}

void printBitNum(unsigned num)
{
	unsigned int n = 1;
	n <<= 31;
	for (int i = 1; i < 33; i++) {
		printf("%d", num & n ? 1 : 0);
		num <<= 1;
		if (i % 8)
			;
		else
			printf(" ");
	}
}