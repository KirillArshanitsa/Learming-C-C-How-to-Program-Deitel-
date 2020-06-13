#include <stdio.h>

unsigned int gcd (unsigned int, unsigned int);

unsigned int gcd(unsigned int num1, unsigned int num2) {
    unsigned int maxNum;
    unsigned int minNum;
    if (num1 > num2) {
        maxNum = num1;
        maxNum = num2;
    }
    else {
        maxNum = num2;
        minNum = num1;
    }

    for (int i = minNum; i > 0; i--) {
        if (maxNum % i == 0 & minNum % i == 0)
            return i;
    }

}

int main(void) {
    printf("Nod is %d", gcd(3, 27));
    return 0;
}