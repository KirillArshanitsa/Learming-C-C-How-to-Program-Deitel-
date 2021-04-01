#include <stdio.h>
#include <stdlib.h>


struct intList
{
	unsigned int i;
	intList* intListPtr;
};

typedef intList IntList;
typedef IntList* IntListPtr;

void generateTestData(IntListPtr*,const unsigned int[], unsigned int);
void printData(IntListPtr);
IntListPtr merge(IntListPtr, IntListPtr);



int main(void)
{
	IntListPtr firstList = NULL;
	IntListPtr secondList = NULL;

	puts("Generate test data:");

	unsigned int firstNum []= {0, 2, 3, 6, 8, 9, 11, 15};
	unsigned int secondNum[] = { 1, 2, 4, 5, 7, 10};

	//unsigned int firstNum[] = { 0,1,3,9 };
	//unsigned int secondNum[] = { 2,4,5,6,7,9,10,11,105 };

	//unsigned int secondNum[] = { 0,1,3,9 };
	//unsigned int firstNum[] = { 2,4,5,6,7,9,10 };

	//unsigned int firstNum[] = { 1};
	//unsigned int secondNum[] = { 0 };
	generateTestData(&firstList, firstNum, sizeof(firstNum) / sizeof(firstNum[0]));
	generateTestData(&secondList, secondNum, sizeof(secondNum) / sizeof(secondNum[0]));
	puts("Print data:");
	printData(firstList);
	printData(secondList);

	puts("Run merge:");
	printData(merge(firstList, secondList));
	return 0;
}


IntListPtr merge(IntListPtr firstList, IntListPtr secondList)
{
	IntListPtr BeginPtr = firstList;
	IntListPtr CurrentPtrFirstList = firstList;
	IntListPtr CurrentPtrSecondList = secondList;
	IntListPtr PrevousPtrList = NULL;
	IntListPtr nextFirstPtr = NULL;
	IntListPtr nextSecondPtr = NULL;


	if (CurrentPtrFirstList->i > CurrentPtrSecondList->i) {
		BeginPtr = CurrentPtrSecondList;
		nextSecondPtr = CurrentPtrSecondList->intListPtr;
		CurrentPtrSecondList->intListPtr = CurrentPtrFirstList;
		PrevousPtrList = CurrentPtrSecondList;
		CurrentPtrSecondList = nextSecondPtr;
	}
	else if (CurrentPtrSecondList->i == CurrentPtrFirstList->i) {
		BeginPtr = CurrentPtrFirstList;
		nextFirstPtr = CurrentPtrFirstList->intListPtr;
		CurrentPtrFirstList->intListPtr = CurrentPtrSecondList;
		nextSecondPtr = CurrentPtrSecondList->intListPtr;
		CurrentPtrSecondList->intListPtr = nextFirstPtr;
		CurrentPtrFirstList = CurrentPtrSecondList;
		PrevousPtrList = CurrentPtrSecondList;
		CurrentPtrSecondList = nextSecondPtr;
	}
	else {
		BeginPtr = CurrentPtrFirstList;
		nextFirstPtr = CurrentPtrFirstList->intListPtr;
		nextSecondPtr = CurrentPtrSecondList->intListPtr;

		if ((nextFirstPtr != NULL) &&(nextFirstPtr->i < CurrentPtrSecondList->i)) {
			CurrentPtrFirstList = nextFirstPtr;
			nextFirstPtr = nextFirstPtr->intListPtr;
			while (nextFirstPtr->i < CurrentPtrSecondList->i) {
				CurrentPtrFirstList = nextFirstPtr;
				nextFirstPtr = nextFirstPtr->intListPtr;
			}
			CurrentPtrFirstList->intListPtr = CurrentPtrSecondList;
			CurrentPtrSecondList->intListPtr = nextFirstPtr;
		}
		else {
			CurrentPtrFirstList->intListPtr = CurrentPtrSecondList;
			CurrentPtrSecondList->intListPtr = nextFirstPtr;
		}
		PrevousPtrList = CurrentPtrFirstList;
		CurrentPtrFirstList = CurrentPtrSecondList;
		CurrentPtrSecondList = nextSecondPtr;
	}
	//printf("BeginPtr = %d\n", BeginPtr== NULL ? -1 : BeginPtr->i);
	//printf("PrevousPtrList = %d\n", PrevousPtrList == NULL ? -1 : PrevousPtrList->i);
	//printf("CurrentPtrFirstList = %d\n", CurrentPtrFirstList == NULL ? -1 : CurrentPtrFirstList->i);
	//printf("CurrentPtrSecondList  %d\n", CurrentPtrSecondList == NULL ? -1 : CurrentPtrSecondList->i);
	//printData(BeginPtr);
	//printData(CurrentPtrSecondList);

	while ((CurrentPtrFirstList->intListPtr != NULL) && (CurrentPtrSecondList != NULL)) {
		if (CurrentPtrFirstList->i > CurrentPtrSecondList->i) {
			PrevousPtrList->intListPtr = CurrentPtrSecondList;
			nextSecondPtr = CurrentPtrSecondList->intListPtr;
			CurrentPtrSecondList->intListPtr = CurrentPtrFirstList;
			PrevousPtrList = CurrentPtrSecondList;
			CurrentPtrSecondList = nextSecondPtr;
		}
		else if (CurrentPtrSecondList->i == CurrentPtrFirstList->i) {
			nextFirstPtr = CurrentPtrFirstList->intListPtr;
			CurrentPtrFirstList->intListPtr = CurrentPtrSecondList;
			nextSecondPtr = CurrentPtrSecondList->intListPtr;
			CurrentPtrSecondList->intListPtr = nextFirstPtr;
			CurrentPtrFirstList = CurrentPtrSecondList;
			PrevousPtrList = CurrentPtrSecondList;
			CurrentPtrSecondList = nextSecondPtr;
		}
		else {
			nextFirstPtr = CurrentPtrFirstList->intListPtr;
			nextSecondPtr = CurrentPtrSecondList->intListPtr;
			if (nextSecondPtr == NULL)
				break;

			if (nextFirstPtr->i < CurrentPtrSecondList->i) {
				CurrentPtrFirstList = nextFirstPtr;
				nextFirstPtr = nextFirstPtr->intListPtr;
				while ((nextFirstPtr != NULL) && (nextFirstPtr->i < CurrentPtrSecondList->i)) {
					CurrentPtrFirstList = nextFirstPtr;
					nextFirstPtr = nextFirstPtr->intListPtr;
				}
				CurrentPtrFirstList->intListPtr = CurrentPtrSecondList;
				CurrentPtrSecondList->intListPtr = nextFirstPtr;
			}
			else {
				CurrentPtrFirstList->intListPtr = CurrentPtrSecondList;
				CurrentPtrSecondList->intListPtr = nextFirstPtr;
			}
			PrevousPtrList = CurrentPtrFirstList;
			CurrentPtrFirstList = CurrentPtrSecondList;
			CurrentPtrSecondList = nextSecondPtr;
		}

	}

	if (CurrentPtrSecondList != NULL) {

		if (CurrentPtrFirstList->i < CurrentPtrSecondList->i) {
			PrevousPtrList = CurrentPtrFirstList;
			CurrentPtrFirstList = CurrentPtrFirstList->intListPtr;
			while ((CurrentPtrFirstList != NULL) && (CurrentPtrFirstList->i < CurrentPtrSecondList->i)){
				PrevousPtrList = CurrentPtrFirstList;
				CurrentPtrFirstList = CurrentPtrFirstList->intListPtr;
			}

			if (CurrentPtrFirstList != NULL) {
				nextFirstPtr = CurrentPtrFirstList->intListPtr;
				CurrentPtrFirstList->intListPtr = CurrentPtrSecondList;
				CurrentPtrSecondList->intListPtr = nextFirstPtr;
			}
			else 
				PrevousPtrList->intListPtr = CurrentPtrSecondList;
			
		}
		//if elem count in CurrentPtrSecondList > elem in CurrentPtrFirstList
		else if ((CurrentPtrFirstList->i > CurrentPtrSecondList->i)) {
			while (CurrentPtrSecondList != NULL) {
				PrevousPtrList->intListPtr = CurrentPtrSecondList;
				nextSecondPtr = CurrentPtrSecondList->intListPtr;
				CurrentPtrSecondList->intListPtr = CurrentPtrFirstList;
				PrevousPtrList = CurrentPtrSecondList;
				CurrentPtrSecondList = nextSecondPtr;
			}
		}
	}

	return BeginPtr;
}




void printData(IntListPtr intListPtr)
{
	while (intListPtr->intListPtr != NULL) {
		printf("%u ", intListPtr->i);
		intListPtr = intListPtr->intListPtr;
	}
	if(intListPtr != NULL)
		printf("%u\n", intListPtr->i);
}

void generateTestData(IntListPtr* intListPtr, const unsigned int numbers[], unsigned int size )
{
	IntListPtr currentPtr;
	IntListPtr nextPtr;

	currentPtr = (IntListPtr)malloc(sizeof(IntList));
	currentPtr->i = numbers[0];
	currentPtr->intListPtr = NULL;
	*intListPtr = currentPtr;


	for (int i = 1; i < size; i++) {
		nextPtr = (IntListPtr)malloc(sizeof(IntList));
		nextPtr->i = numbers[i];
		nextPtr->intListPtr = NULL;

		currentPtr->intListPtr = nextPtr;
		currentPtr = nextPtr;
	}

}