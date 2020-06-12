#include <stdio.h>

double getMinNum(double, double, double);

double getMinNum(double num1, double num2, double num3){
    double minNun = num1;
    if (minNun > num2)
        minNun = num2;
    if (minNun > num3)
        minNun = num3;
    return minNun;
}

int main(void) {
    printf("Min num is %.2f", getMinNum(0.6, 0.42, 2));
    return 0;
}