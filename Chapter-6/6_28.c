#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertRandNumInArray(int [], int);
void printArray(const int [], int);
int getEqualsVal(const int [], int, int[]);

void insertRandNumInArray(int beginArray[], int size){
    for (int e = 0 ; e < size; e++){
        beginArray[e] = 1 + rand() % 21;
    }
}

void printArray(const int beginArray[], int size){
    for (int e = 0 ; e < size; e++){
        printf("%3d ", beginArray[e]);
    }
    puts("");
}

int getEqualsVal(const int beginArray[] , int size, int equalsVal[]){
    int checkVal;
    int countEquals = 0;
    for (int e = 1; e < size ; e++) {
        checkVal = beginArray[e - 1];
        for (int i = e; i < size; i++) {
            if (checkVal == beginArray[i]) {
                equalsVal[i] = i;
                ++countEquals;
            }
        }
    }
    return countEquals;
}


int main(void){
    srand(time(NULL));
    int sizeResultArray;
    int countEquals;
    int beginArray[20];
    int equalsVal[20] = { 0 };
    insertRandNumInArray(beginArray, 20);
    puts("Begin array");
    printArray(beginArray, 20);
    countEquals = getEqualsVal(beginArray, 20, equalsVal);

    if (countEquals == 0)
        printf("%s", "Array not contains equal value");
    else{
        sizeResultArray = 20 - countEquals;
        int resultArray[sizeResultArray];
        for (int e = 0, i = 0; e < 20; e++){
              //printf("%4d", equalsVal[e]);
              if (equalsVal[e] == 0) {
                  resultArray[i] = beginArray[e];
                  ++i;
              }
        }
        puts("Array with equal values");
        printArray(equalsVal, 20);
        printf("\nEquals count is %d\n", countEquals);
        printf("%s %d\n", "Result Array size is", sizeResultArray);
        printArray(resultArray, sizeResultArray);
    }
    return 0;
}