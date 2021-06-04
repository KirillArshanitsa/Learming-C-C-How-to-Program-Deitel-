#include<stdio.h>

#define MINIMUM2(x,y) ((x < y)? printf("Min is %d", x): printf("Min is %d", y))

int main(void){
    int x, y;
    puts("Enter two digits:");
    scanf("%d %d", &x, &y);
    MINIMUM2(x,y);
    return 0;
}