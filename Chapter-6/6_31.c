#include <stdio.h>
#define ARRAYSIZE 6

int buckedSort(int[], int);
void printArray(int[], int);
void clearArray(int[][ARRAYSIZE], int);
int getMaxRankNum(int[], int);

int getMaxRankNum(int array[], int size) {
    int maxNum = array[0];
    int divider = 10;
    int result = 1;

    for (int e = 1; e < size; e++) {
        if (maxNum < array[e])
            maxNum = array[e];
    }
    while (maxNum / divider) {
        divider *= 10;
        ++result;
    }

    return result; 
}

void clearArray(int twoDimensionalArray[][ARRAYSIZE], int size) {
    for (int ext = 0; ext < 10; ext++) {
        for (int in = 0; in < ARRAYSIZE; in++) {
            twoDimensionalArray[ext][in] = -1;
        }
    }
}

int buckedSort(int array[], int size) {
    int twoDimensionalArray[10][ARRAYSIZE];
    int arraySize;
    int stingNumArray;
    int divider = 10;
    int count = getMaxRankNum(array, size);

    while (count--) {
        arraySize = 0;
        clearArray(twoDimensionalArray, size);

        for (int e = 0; e < size; e++) {
            if ((array[e] % divider) == array[e]) {
                stingNumArray = array[e] / (divider / 10);
            }
            else {
                stingNumArray = array[e] % divider;
            }
            twoDimensionalArray[stingNumArray][e] = array[e];
        }

        for (int ext = 0; ext < 10; ext++) {
            for (int in = 0; in < ARRAYSIZE; in++) {
                if (twoDimensionalArray[ext][in] != -1) {
                    if (arraySize <= size) {
                        array[arraySize] = twoDimensionalArray[ext][in];
                        ++arraySize;
                    }
                    else {
                        printf("Error insert in position %d in array size = %d\n", arraySize, size);
                        return -1;
                    }
                }
            }
        }
        divider *= 10;
    }
    return 0;
}

void printArray(int array[], int size) {
    for (int e = 0; e < size; e++) {
        printf("%5d", array[e]);
    }
    puts("");
}

int main(void) {
    int myArray[ARRAYSIZE] = { 97,300,100,400, 5, 1007 };
    printArray(myArray, ARRAYSIZE);
    buckedSort(myArray, ARRAYSIZE);
    printArray(myArray, ARRAYSIZE);
    return 0;
}