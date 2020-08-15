#include <stdio.h>
#define SIZE 5

int searchVal;
int linearSearh(const int[], int);

int linearSearh(const int Array[], int size){
    //printf("%d\n", size);
    if (size < 0)
        return -1;
    if(Array[--size] == searchVal)
        return size;
    else return linearSearh(Array, size);
}

int main(void){
    int myArray[SIZE] = {0,2,3,4,5};
    searchVal = 0;
    printf("%d\n",  linearSearh(myArray, SIZE));
    return 0;
}