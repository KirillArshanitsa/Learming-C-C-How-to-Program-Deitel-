#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define MAX_GEN_NUM 15

void shiftInArray(int[], int, int);
int deleteEquals(int [], int);
void printArray(int [], int);
int insertVal(int[], int, unsigned int);

int main(void)
{
    int array[SIZE];
    unsigned int insretPos = 0;
    srand(time(NULL));

    printf("Fill array size = %d, max num = %d\n",SIZE, MAX_GEN_NUM);
    for (int i = 0, tmpNum ;i < SIZE; i++){
        tmpNum = rand() % MAX_GEN_NUM;
        //printf("Try insert %d\n", tmpNum);
        if(insertVal(array, tmpNum, insretPos))
            insretPos++;
    }
    printf("\n\nInserted num = %d\n", insretPos);
    puts("Print array");
    printArray(array, insretPos);


    return 0;
}

int insertVal(int array[], int value, int insertedPostition)
{
    for (int i = 0; i <= insertedPostition ;i++){
        if(array[i] == value) {
            printf("Duplicated value %d\n", value);
            return 0;
        }
    }
    array[insertedPostition] = value;
    return 1;
}


void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    puts("");
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