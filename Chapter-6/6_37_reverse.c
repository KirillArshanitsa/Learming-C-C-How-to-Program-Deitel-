#include<stdio.h>

void printArrya(int[], int);

void printArrya(int Array[], int size){
	if (size == 0)
		return;
	printf("%2d", Array[--size]);
	printArrya(Array, size);
}

int main(void) {

	int myArray[] = {1,2,3,4,5};

	printArrya(myArray, 5);
	return 0;
}