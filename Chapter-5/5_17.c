#include <stdio.h>

int multiple(int, int);
int multiple(int num1, int num2){
    return num1 % num2 > 0 ? 1 : 0;
}

int main(void) {
    printf("%d", multiple(4,3));
    return 0;
}