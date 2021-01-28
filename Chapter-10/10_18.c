#include <stdio.h>

void displayBits(unsigned int value); 

int main(void)
{
    unsigned int x;

    printf("%s", "Enter a nonnegative int: ");
    scanf_s("%u", &x);

    displayBits(x);
}


void displayBits(unsigned int value)
{
    int bitSize = sizeof(value);
    int bitsMove;
    if (bitSize == 2)
        bitsMove = 16;
    else if(bitSize == 4)
        bitsMove = 33;
    else {
        puts("Error detect size of int");
        return;
    }

    unsigned int displayMask = 1 << (bitsMove - 1);
    printf("%10u = ", value);

    for (unsigned int c = 1; c <= bitsMove; ++c) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1;    

        if (c % 8 == 0) { 
            putchar(' ');
        }
    }

    putchar('\n');
}



