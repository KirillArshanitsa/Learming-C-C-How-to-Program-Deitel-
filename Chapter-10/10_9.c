#include <stdio.h>

union floatingPoint{
    float f;
    double d;
    long double x;
};

int main(void){
    union floatingPoint myFloatingPoint;

    scanf("%f",&myFloatingPoint.f);
    scanf("%lf",&myFloatingPoint.d);
    scanf("%Lf",&myFloatingPoint.x);
    

    printf("%f\n", myFloatingPoint.f);
    //scanf("%hd",&myInteger.s);
    printf("%f\n", myFloatingPoint.d);
    //scanf("%d",&myInteger.i);
    printf("%Lf\n", myFloatingPoint.x);

    return 0;
}