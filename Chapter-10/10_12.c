#include <stdio.h>
#include <math.h>

void power2(unsigned, unsigned);
void printBitNum(unsigned);

int main(void)
{
	unsigned number = 3;
	unsigned pow = 3 ;
	power2(number, pow);
	return 0;
}

void power2(unsigned number, unsigned pows) 
{
	printf("Origin operation = %u\n", number * (unsigned) pow(2, pows));
	while (pows--)
		number <<= 1;

	printf("Decimal result = %u\n", number);
	printf("Bit result = ");
	printBitNum(number);
}

void printBitNum(unsigned int num)
{
	int n = 1;
	n <<= 31;
	for (int i = 1 ; i < 33; i++) {
		printf("%d", num & n ? 1:0 );
		num <<= 1;
		if (i % 8)
			;
		else
			printf(" ");
	}
}