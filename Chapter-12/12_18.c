#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define MAX_GEN_NUM 12

void fillArray(int [], int);
void shiftInArray(int[], int, int);
int deleteEquals(int [], int);
void printArray(int [], int);

int main(void)
{
    int array[SIZE];
    srand(time(NULL));

    printf("Fill array size = %d, max num = %d\n",SIZE, MAX_GEN_NUM);
    fillArray(array, SIZE);
    puts("Print array before:");
    printArray(array, SIZE);
    puts("Print array after:");
    printArray(array, deleteEquals(array, SIZE));

    return 0;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    puts("");
}

void fillArray(int array[], int size)
{
    for (int i = 0 ;i < size; i++){
        array[i] = rand() % MAX_GEN_NUM;
    }
}

void shiftInArray(int array[], int beginShift, int endShift)
{
    while(beginShift < endShift){
        array[beginShift] = array[beginShift + 1];
        beginShift++;
    }
}

int deleteEquals(int array[], int size)
{
    for (int compareInt = 0; compareInt < size; compareInt++){
        for (int i = compareInt + 1 ; i < size ;){
            if(array[compareInt] == array[i]){
                shiftInArray(array, i, size);
                size--;
            }
            i++;
        }
    }

    return size;
}