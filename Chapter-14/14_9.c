#include <stdio.h>

void print();
void print2();

int main()
{
    print();
    puts("");
    print2();
    return 0;
}

void print2()
{
    for (int e = 0; e < 25; e++){
        if((e == 0) || (e == 20)) {
            for (int i = 0; i < 5; i++)
                printf("*");
        }
        else{
            printf("*");
            for (int i = 0;i < 3;i++)
                printf(" ");
            printf("*");
        }
        printf("\n");
        e += 4;
    }
}

void print()
{
    int i = 0;
    while(++i <= 25){
        if ((i <= 5) || (i >= 20))
            printf("*");
        else{
            printf("*");
            for (int e= 0; e < 3 ; e++)
                printf(" ");
            printf("*");
            i += 4;
        }
        if ((i % 5) == 0)
            printf("\n");
    }
}