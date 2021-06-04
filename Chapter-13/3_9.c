#include<stdio.h>

#define PRINTARRAY(x,y) for (int e = 0; e < y; e++) printf("%d ", x[e]);

int main(void){
    int array[10];
    for (int i = 0; i < 10; i++ )
        array[i] = i;

    PRINTARRAY(array, 10);
    return 0;
}