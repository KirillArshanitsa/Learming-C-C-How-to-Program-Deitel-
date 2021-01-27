#include <stdio.h>

unsigned packCharacters(char[]);
void printBitNum(unsigned short);
void unpackCharacters(unsigned short, char[]);

int main(void)
{
	unsigned short resultNum;
	char elem[2] = { 'a','b' };
	char revertElem[2] = {0};

	puts("Ener two characters:");
	//scanf_s("%2c", elem);

	puts("Print bits first char:");
	printBitNum(elem[0]);
	puts("\nPrint bits second char:");
	printBitNum(elem[1]);

	puts("\n\nPrint packCharacters result:");
	resultNum = packCharacters(elem);
	printBitNum(resultNum);
	printf("\nDecimal result = %d\n", resultNum);

	puts("\nRevert");
	unpackCharacters(resultNum, revertElem);
	printf("Chars - %c %c\n", revertElem[0], revertElem[1]);
	puts("Binary:");
	printBitNum(revertElem[0]);
	puts("");
	printBitNum(revertElem[1]);
}

void unpackCharacters(unsigned short num, char elem[]) 
{
	char firstChar;
	char secondChar;
	firstChar = (num & 65280) >> 8;
	secondChar = num & 255;
	elem[0] = firstChar;
	elem[1] = secondChar;
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