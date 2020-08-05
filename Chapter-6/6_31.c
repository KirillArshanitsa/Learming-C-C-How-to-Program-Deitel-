#include <stdio.h>

void buckedSort(int[], int);
void printArray(int[], int);

void buckedSort(int array[], int size){
    int twoDimensionalArray[10][size - 1];
    for (int e = 0; e < size - 1; e++){
        twoDimensionalArray[array[e] % 10][e] = array[e];
    }

    for (int e = 0; e < size -1; e++){
        array[e] = twoDimensionalArray[array[e] % 10][e];
    }
}

void printArray(int array[], int size){
    for (int e = 0; e < size; e++){
        printf ("%5d", array[e]);
    }
}

int main(void){
    int myArray[5] = {97,3,100,4,5};
    //buckedSort(myArray, 5);
    //printArray(myArray, 5);;
    return 0;
}