#include <stdio.h>

union integer{
    char c;
    short s;
    int i;
    long l;
};

int main(void){
    union integer myInteger;

    scanf("%c",&myInteger.c);
    scanf("%hd",&myInteger.s);
    scanf("%d",&myInteger.i);
    scanf("%ld",&myInteger.l);


    printf("%c\n", myInteger.c);
    //scanf("%hd",&myInteger.s);
    printf("%hd\n", myInteger.s);
    //scanf("%d",&myInteger.i);
    printf("%d\n", myInteger.i);
    //scanf("%ld",&myInteger.l);
    printf("%ld\n", myInteger.l);
    return 0;
}