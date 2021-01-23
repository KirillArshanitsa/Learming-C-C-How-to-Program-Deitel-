#include <stdio.h>

void printBit(int);

int main(void){
    int a;
    scanf("%d",&a);
    puts("Before:");
    printBit(a);
    puts("\nAfter:");
    a <<= 4;
    printBit(a);
    return 0;
}

void printBit(int num)
{
    int mask = 1 << 31;
    for(int i = 0; i < 32; i++) {
        printf("%d", mask & num ? 1 : 0);
        num <<= 1;
        if (i % 8 == 0)
            printf(" ");
    }
}