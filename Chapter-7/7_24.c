#include <stdio.h>
#define SIZE 10

void printArray(const int[], const int);
void quicksort(int[], int, int);
void partition(int[], int);

void printArray(const int array[], const int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	puts("");
}

void quicksort(int array[], int beginVal, int finishVal) {
	partition(array, finishVal);
}

void partition(int array[], int size) {
	int leftVal = 0;
	int rightVal = size;
	int tmpVal;

	for (int i = rightVal - 1; i > 0; i--) {
		if (array[leftVal] > array[i]) {
			tmpVal = array[leftVal];
			array[leftVal] = array[i];
			array[i] = tmpVal;
			rightVal = i;
			break;
		}
	}

	for (int i = leftVal + 1; i < rightVal; i++) {
		if (array[rightVal] < array[i]) {
			tmpVal = array[rightVal];
			array[rightVal] = array[i];
			array[i] = tmpVal;
			leftVal = i;
			break;
		}
	}
}

int main(void) {
	int myArray[SIZE] = { 37,2,6,4,89,8,10,12,68,45 };
	printArray(myArray, SIZE);
	quicksort(myArray, 0 , SIZE);
	printArray(myArray, SIZE);
	return 0;
}