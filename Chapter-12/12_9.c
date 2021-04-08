#include <stdio.h>
#include <stdlib.h>

#define CHARS_COUNT 100

struct charList {
	char symbol;
	charList* charListPtr;
};

typedef charList CharList;
typedef CharList *CharListPtr;

void insert(CharListPtr *, char);
void printElems(CharListPtr);
char revert(CharListPtr, CharListPtr *);

int main(void) 
{
	CharListPtr charList = NULL;
	CharListPtr revertCharList = NULL;

	for (int i = 0; i < CHARS_COUNT; i++)
		insert(&charList, 33 + rand() % 94); //33-126 cahrs 

	puts("Print original list:");
	printElems(charList);
	puts("\nRun revert:");
	revert(charList, &revertCharList);
	puts("Print reverted original list:");
	printElems(revertCharList);

	return 0;
}


char revert(CharListPtr originCharListPtr, CharListPtr *revertCharList)
{
	static CharListPtr prevousRevertListPtr;

	if (originCharListPtr == NULL)
		return NULL;
	else {
		CharListPtr revertElemPtr = (CharListPtr)malloc(sizeof(CharListPtr));
		if (revertElemPtr != NULL) {
			revertElemPtr->charListPtr = prevousRevertListPtr;
			prevousRevertListPtr = revertElemPtr;
			*revertCharList = revertElemPtr;

			revertElemPtr->symbol = originCharListPtr->symbol;
			char originalChar = revert(originCharListPtr->charListPtr, revertCharList);

			return originCharListPtr->symbol;
		}
		else {
			puts("Error create list elem\n");
			return NULL;
		}
	}

}


void printElems(CharListPtr charListPtr) {
	while (charListPtr != NULL) {
		printf("%c ", charListPtr->symbol);
		charListPtr = charListPtr->charListPtr;
	}
}


void insert(CharListPtr *charListPtr, char symbol)
{
	CharListPtr currentPtr = *charListPtr;
	CharListPtr prevousPtr = NULL;
	CharListPtr nextPtr = (CharListPtr) malloc(sizeof(CharList));

	if (nextPtr != NULL) {
		nextPtr->symbol = symbol;
		nextPtr->charListPtr = NULL;

		if (currentPtr == NULL) {
			*charListPtr = nextPtr;
			return;
		}

		while (currentPtr != NULL) {
			prevousPtr = currentPtr;
			currentPtr = currentPtr->charListPtr;
		}

		prevousPtr->charListPtr = nextPtr;

	}
	else {
		printf("Error create list elem with char %c\n", symbol);
	}

}

