#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_COUNT 25
#define MAX_NUM 100

struct listNum {
	unsigned int e;
	listNum *listNumPtr;
};

typedef struct listNum ListNum;
typedef ListNum * ListNumPtr;


void insert(ListNumPtr *, unsigned int );
void printList(ListNumPtr);
void getSumAndAverage(ListNumPtr);


int main(void) 
{
	ListNumPtr listNumPtr = NULL;
	srand(time(NULL));

	for (int e = 0; e < NUMBER_COUNT; e++) 
		insert(&listNumPtr, rand() % (MAX_NUM + 1));

	puts("Print values:");
	printList(listNumPtr);
	getSumAndAverage(listNumPtr);

	return 0;
}

void getSumAndAverage(ListNumPtr listNumPtr)
{
	double average = 0;
	unsigned int sum = 0;

	while (listNumPtr != NULL) {
		sum += listNumPtr->e;
		listNumPtr = listNumPtr->listNumPtr;
	}

	printf("Sum is %u\nAverage is %.2f\n", sum, (double)(sum / NUMBER_COUNT));
}

void printList(ListNumPtr listNumPtr)
{
	if (listNumPtr == NULL) {
		puts("List is empty");
	}
	else {
		printf("%u", listNumPtr->e);
		listNumPtr = listNumPtr->listNumPtr;
		while (listNumPtr != NULL) {
			printf(" -> %u", listNumPtr->e);
			listNumPtr = listNumPtr->listNumPtr;
		}
	}
	puts("\n");
}


void insert(ListNumPtr *listNumPtr, unsigned int value){
	ListNumPtr currentPtr = *listNumPtr;
	ListNumPtr prevousPtr = NULL;
	ListNumPtr nextPtr;

	nextPtr = (ListNumPtr) malloc(sizeof(ListNum));
	if (nextPtr != NULL) {
		nextPtr->e = value;
		nextPtr->listNumPtr = NULL;
		while ((currentPtr != NULL) && (value > currentPtr->e)){
			prevousPtr = currentPtr;
			currentPtr = currentPtr->listNumPtr;
		}

		if (prevousPtr == NULL) {
			nextPtr->listNumPtr = currentPtr;
			*listNumPtr = nextPtr;
		}
		else {
			prevousPtr->listNumPtr = nextPtr;
			nextPtr->listNumPtr = currentPtr;
		}
	}
	else {
		printf("Cannot insert %u\n", value);
	}

}