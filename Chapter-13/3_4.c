#include<stdio.h>
#define PI 3.14159
#define ballVolume(radius) ((4.0 / 3) * PI * radius * radius * radius)

int main(void){
    for (int i = 1 ; i <= 10 ;i++)
        printf("%d\t%lf\n", i , ballVolume(i));

    return 0;
}