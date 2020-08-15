#include<stdio.h>


int searchVal;
int binarySearch(int[], int, int);

int binarySearch(int Array[], int beginVal, int finalVal) {
	if (beginVal == finalVal)
		return -1;

	int middleVal = (finalVal - beginVal ) / 2 + beginVal;

	if (Array[middleVal] == searchVal)
		return middleVal;
	else if (Array[middleVal] < searchVal)
		beginVal = middleVal;
	else
		finalVal = middleVal;

	return binarySearch(Array, beginVal, finalVal);
}

int main(void) {
	searchVal = 4;
	int myArray[] = {1,2,3,4};

	printf ("%d", binarySearch(myArray, 0, 4));
	return 0;
}