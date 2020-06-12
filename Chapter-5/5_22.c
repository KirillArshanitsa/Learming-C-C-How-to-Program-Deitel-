#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int divisionRemainder(int, int);
int divisionWithoutRemainder(int, int);
int printDigits(int);

int divisionRemainder(int num1, int num2) {
    return num1 % num2;
}

int divisionWithoutRemainder(int num1, int num2) {
    return num1 / num2;
}

int printDigits(int num) {
    if (divisionWithoutRemainder(num, 10)) {
        printDigits(divisionWithoutRemainder(num, 10));
        printf("  %d", divisionRemainder(num, 10));
    }
    else {
        printf_s("%d", num);
        return 1;
    }
}


int main(void) {
    srand(time(NULL));
    int n;
    printf("%d\n", n = rand());
    printDigits(n);
    return 0;
}