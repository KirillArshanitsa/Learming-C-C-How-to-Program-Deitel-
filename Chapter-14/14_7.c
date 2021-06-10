#include<stdio.h>
#include<stdlib.h>

void printArray(const int [], int);

int main()
{
    int* arrayIntPtr = NULL;
    int arraySize = 0;
    int tmpNum;
    puts("Enter array size:");
    scanf("%d", &arraySize);

    arrayIntPtr = (int*) (calloc(arraySize, sizeof(int)));
    if(arrayIntPtr == NULL){
        puts("Error create array.");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < arraySize; i++){
        puts("Enter elem:");
        scanf("%d", &tmpNum);
        arrayIntPtr[i] = tmpNum;
    }
    puts("Print array:");
    printArray(arrayIntPtr, arraySize);

    arrayIntPtr = (int*) realloc(arrayIntPtr, arraySize / 2);

    if(arrayIntPtr == NULL){
        puts("Error create new array.");
        exit(EXIT_FAILURE);
    }

    puts("Print array:");
    printArray(arrayIntPtr, arraySize / 2);

    return 0;
}

void printArray(const int array[], int size)
{
    for(int i = 0;i < size ;i++)
        printf("%d ", array[i]);
    puts("");
}