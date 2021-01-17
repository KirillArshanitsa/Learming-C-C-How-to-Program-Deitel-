#include <stdio.h>
#include <string.h>
#define MAX_STR_SIZE_NUM 100

void checkOutD(const int *,  unsigned int);
void checkOutF(const float *, unsigned int);

int main(void)
{
    int x = 12345;
    float y = 1.2345;
    puts("Chek integer");
    checkOutD(&x, 5);
    checkOutD(&x, 6);
    checkOutD(&x, 2);
    puts("\nChek float ");
    checkOutF(&y, 12);
    checkOutF(&y, 1);
}

void checkOutF(const float *floatPtr, const unsigned int size)
{
    //only 1.2345 in %g
    char strNum [MAX_STR_SIZE_NUM];
    size_t sizeNum;
    int printedSize;

    sprintf(strNum,"%g", *floatPtr);
    sizeNum = strlen(strNum);
    printedSize = printf("%*g", size, *floatPtr);
    if(sizeNum == printedSize)
        puts("\nEquals");
    else if(sizeNum > printedSize)
        puts("\nRouding original number");
    else
        puts("\nAdd prited number");
}

void checkOutD(const int *intPtr, const unsigned int size)
{
    int sizeNum = 0;
    int printedSize;
    for(int copyNum = *intPtr; copyNum > 0;copyNum /= 10)
        ++sizeNum;
    printedSize = printf("%*d", size, *intPtr);
    if(sizeNum == printedSize)
        puts("\nEquals");
    else if(sizeNum > printedSize)
        puts("\nRouding original number");
    else
        puts("\nAdd prited number");
}
