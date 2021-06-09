#include<stdio.h>

#define MINIMUM2(x,y) ((x < y)? x: y)
#define MINIMUM3(x,y,z)( MINIMUM2(x, y) > z ? z : MINIMUM2(x, y))

int main(void){
    int x, y, z;
    puts("Enter three digits:");
    scanf("%d %d %d", &x, &y, &z);
    printf("%d", MINIMUM3(x,y, z));
    return 0;
}