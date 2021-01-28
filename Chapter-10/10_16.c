#include <stdio.h>

#define CHAR_COUNT 4
#define BIT_MOVE 24 //(-8 for first move)

unsigned packCharacters(char[]);
void printBitNum(unsigned );
void unpackCharacters(unsigned , char[]);

int main(void)
{
	unsigned resultNum;
	char elem[CHAR_COUNT] = { 0 };
	char revertElem[CHAR_COUNT] = {0};

	printf("Ener %u characters:", CHAR_COUNT);
	//scanf_s("%*c", CHAR_COUNT, elem);
	scanf_s("%4c", elem);
	 for (int e = 0; e < CHAR_COUNT;e++){
		printf("\nPrint bits %d char %c:\n", e, elem[e]);
		printBitNum(elem[e]);
	}

	puts("\n\nPrint pack characters result:");
	resultNum = packCharacters(elem);
	printBitNum(resultNum);
	printf("\nDecimal result = %u\n", resultNum);

	puts("\nRevert");
	unpackCharacters(resultNum, revertElem);
	for (int e = 0; e < CHAR_COUNT; e++) {
		printf("Num char = %d char = %c\n", e, revertElem[e]);
	}

}

void unpackCharacters(unsigned num, char elem[]) 
{
	for (unsigned int i = 0, mask = 255 << BIT_MOVE, bitMove = BIT_MOVE;  i < CHAR_COUNT;  i++) {
		elem[i] = (num & mask) >> bitMove;
		bitMove -= 8;
		mask = 255 << bitMove;
	}
}

unsigned packCharacters(char elem[])
{
	unsigned result = 0;
	for (unsigned int e = 0, bitMove = BIT_MOVE; e < CHAR_COUNT; e++, bitMove -= 8) {
		result |= (elem[e] << bitMove);
	}
	return result;
}


void printBitNum(unsigned num)
{
	printf("Origin num = %u\n", num);
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