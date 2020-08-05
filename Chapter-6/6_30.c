#include <stdio.h>
#define ARRAYSIZE 1000

void getSimpleNum(int [], int);
void printResult(int [], int);

void printResult(int array[], int size) {
    for (int e = 1; e < size; e++ ){
        if (array[e] != 0 )
            printf("%d\n", e);
    }
}

void getSimpleNum(int array[], int size){
    for (int e = 2; e < size; e++ )
        if (array[e] == 1){
            for (int i = e + 1 ; i < size; i++ ){
                if (i % e == 0)
                    array[i] = 0;
            }
        }

}

int main(void){
    int array[ARRAYSIZE];
    for (int e = 0 ; e < ARRAYSIZE; e++)
        array[e] =1;

    getSimpleNum(array, ARRAYSIZE);
    printResult(array, ARRAYSIZE);
    return 0;
}