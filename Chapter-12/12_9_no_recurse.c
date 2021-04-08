#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHARS_COUNT 10

struct charList {
	char symbol;
	charList* charListPtr;
};

typedef charList CharList;
typedef CharList* CharListPtr;

void insert(CharListPtr*, char);
void printElems(CharListPtr);
void revert(CharListPtr, CharListPtr*);

int main(void)
{
	srand(time(NULL));
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


void revert(CharListPtr originCharListPtr, CharListPtr *revertCharList)
{
	CharListPtr prevousRevertListPtr = NULL;
	CharListPtr revertElem = NULL;

	while (originCharListPtr != NULL) {
		revertElem = (CharListPtr)malloc(sizeof(CharList));
		if (revertElem != NULL) {
			revertElem->charListPtr = prevousRevertListPtr;
			prevousRevertListPtr = revertElem;
			revertElem->symbol = originCharListPtr->symbol;
			*revertCharList = revertElem;
			originCharListPtr = originCharListPtr->charListPtr;
		}
		else {
			puts("Error create list elem.");
			return;
		}
	}

}


void printElems(CharListPtr charListPtr) {
	while (charListPtr != NULL) {
		printf("%c ", charListPtr->symbol);
		charListPtr = charListPtr->charListPtr;
	}
}


void insert(CharListPtr* charListPtr, char symbol)
{

	CharListPtr currentPtr = *charListPtr;
	CharListPtr prevousPtr = NULL;
	CharListPtr nextPtr = (CharListPtr)malloc(sizeof(CharList));

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

