#include<stdio.h>

int recursiveMinimum(int[], int);

int recursiveMinimum(int Array[], int size) {

	if (size == 0)
		return Array[size];

	return Array[size] < recursiveMinimum(Array, size - 1) ? Array[size] : recursiveMinimum(Array, size - 1);
}

int main(void) {

	int myArray[] = { 1,-2,3,4,-5 };

	printf("%d", recursiveMinimum(myArray, 4));
	return 0;
}