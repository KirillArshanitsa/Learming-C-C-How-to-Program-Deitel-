#include <stdio.h>

unsigned packCharacters(char[]);
void printBitNum(unsigned short);

int main(void)
{

	unsigned short resultNum;
	char elem[2];// = { 'a','b' };
	puts("Ener two characters:");
	scanf_s("%2c", elem);

	puts("Print bits first char:");
	printBitNum(elem[0]);
	puts("\nPrint bits second char:");
	printBitNum(elem[1]);

	puts("\n\nPrint packCharacters result:");
	resultNum = packCharacters(elem);
	printBitNum(resultNum);
	printf("\nDecimal result = %hd\n", resultNum);
}

unsigned packCharacters(char elem[])
{
	unsigned result;
	unsigned firstChar = elem[0] ;
	firstChar <<= 8;
	result = firstChar | elem[1];
	return result;
}


void printBitNum(unsigned short num)
{
	int n = 1;
	n <<= 15;
	for (int i = 1; i < 17; i++) {
		printf("%d", num & n ? 1 : 0);
		num <<= 1;
		if (i % 8)
			;
		else
			printf(" ");
	}
}