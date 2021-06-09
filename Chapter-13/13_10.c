#include<stdio.h>

#define SUMMARY(x,y)  int r = 0; for (int e = 0; e < y; e++)  r += x[e];  printf("Sum is %d\n", r);

int main(void){
    int array[10];
    for (int i = 0; i < 10; i++ )
        array[i] = i;
    SUMMARY(array, 10)
    //printf("Sum is = %d\n", a);
    return 0;
}