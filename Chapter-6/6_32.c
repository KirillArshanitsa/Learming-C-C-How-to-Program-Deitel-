#include <stdio.h>

void selectionSort(int[], int);
void printArray(int[], int);


void printArray(int array[], int size) {
    for (int e = 0; e < size; e++) {
        printf("%5d", array[e]);
    }
    puts("");
}

void selectionSort(int array[], int size){
    static int INITNUM;

    if (size == INITNUM + 1)
        return;

    int minValNum = -1;
    int minVal = array[INITNUM];
    for (int e = INITNUM + 1 ; e < size; e++){
        if (minVal > array[e]) {
            minVal = array[e];
            minValNum = e;
        }
    }
    if (minValNum == -1)
        return;
    array[minValNum] = array[INITNUM];
    array[INITNUM] = minVal;
    ++INITNUM;

    selectionSort(array, size);
}

int main(void) {
    int myArray[6] = { 97,5,100,400, 300, 1007 };
    puts("Begin array");
    printArray(myArray, 6);
    puts("");
    selectionSort(myArray, 6);
    puts("After sorting");
    printArray(myArray, 6);
    return 0;
}