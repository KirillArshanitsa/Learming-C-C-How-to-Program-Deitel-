#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT_IN_LIST 10

struct charList {
	char symbol;
	charList *charListPtr;
};

typedef charList *CharListPtr;

void concatenate(CharListPtr, CharListPtr);
void generateData(CharListPtr *);
void printData(CharListPtr);


int main(void) 
{
	CharListPtr firstListPtr = NULL;
	CharListPtr secondListPt = NULL;

	srand(time(NULL));
	puts("Generate test data in first list:");
	generateData(&firstListPtr);
	printData(firstListPtr);
	puts("\nGenerate test data in second list:");
	generateData(&secondListPt);
	printData(secondListPt);
	printf("\nRun concatenate:");
	concatenate(firstListPtr, secondListPt);
	puts("\nPrint new data in first list:");
	printData(firstListPtr);


	return 0;
}

void printData(CharListPtr charListPtr)
{

	while (charListPtr->charListPtr != NULL) {
		printf("%4c", charListPtr->symbol);
		charListPtr = charListPtr->charListPtr;
	}
	printf("%4c\n", charListPtr->symbol);
}

void generateData(CharListPtr *charListPtr)
{
	CharListPtr currentPtr = (CharListPtr)malloc(sizeof(charList));
	CharListPtr nextPtr;

	*charListPtr = currentPtr;
	currentPtr->symbol = rand() % 255;
	//currentPtr->charListPtr = NULL;

	for (int i = 0, count = COUNT_IN_LIST - 1; i < count; i++) {
		nextPtr = (CharListPtr)malloc(sizeof(charList));
		nextPtr->symbol = rand() % 255;
		nextPtr->charListPtr = NULL;
		currentPtr->charListPtr = nextPtr;

		currentPtr = nextPtr;
	}
}

void concatenate(CharListPtr firstListPtr, CharListPtr secondListPtr)
{
	while (firstListPtr->charListPtr != NULL) 
		firstListPtr = firstListPtr->charListPtr;
	
	firstListPtr->charListPtr = secondListPtr;

}