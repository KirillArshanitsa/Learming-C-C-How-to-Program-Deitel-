#include <stdio.h>
#define SIZE 10

void printArray(const int[], const int);
void quicksort(int[], int, int);
int partition(int[], int, int);

void printArray(const int array[], const int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	puts("");
}

void quicksort(int array[], int beginVal, int finishVal) {
	if (finishVal - beginVal <= 1)
		return;

	int position = partition(array, beginVal, finishVal);
	quicksort(array, beginVal, position);
	quicksort(array, position + 1, finishVal);
}

//TODO Change it
int partition(int array[], int beginVal, int finishVal) {
	int leftVal = beginVal;
	int rightVal = finishVal;
	int tmpVal;
	int checkSort;
	int moveVal = array[beginVal];

	while(1) {
		checkSort = 1;
		for (int i = rightVal - 1; i > leftVal; i--) {
			if (array[leftVal] > array[i]) {
				tmpVal = array[leftVal];
				array[leftVal] = array[i];
				array[i] = tmpVal;
				rightVal = i; 
				checkSort = 0;
				break;
			}
		}

		if (checkSort)
			break;
		checkSort = 1;

		for (int i = leftVal + 1; i < rightVal; i++) {
			if (array[rightVal] < array[i]) {
				tmpVal = array[rightVal];
				array[rightVal] = array[i];
				array[i] = tmpVal;
				leftVal = i;
				checkSort = 0;
				break;
			}
		}
		if (checkSort)
			break;
	}

	for (int i = 0; i < finishVal; i++) {
		if (array[i] == moveVal)
			return i;
	}	

}

int main(void) {
	int myArray[SIZE] = { 37,2,6,4,89,8,10,12,68,45 };
	//int myArray[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
	//int myArray[SIZE] = { 9,8,7,6,5,4,3,2,1,0 };

	puts("Array before sort:");
	printArray(myArray, SIZE);
	quicksort(myArray, 0, SIZE);
	puts("Array after sort:");
	printArray(myArray, SIZE);
	return 0;
}