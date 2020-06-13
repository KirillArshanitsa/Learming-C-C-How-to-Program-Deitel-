#include <stdio.h>

unsigned int  revert (unsigned int);

unsigned int  revert(unsigned int num) {
    unsigned int result;
    unsigned int decimalCount;
    for (int i = 10; num / i; i *= 10)
        decimalCount = i;
    for (result = 0; num / 10; num /= 10, decimalCount /= 10)
        result = result + (num % 10) * decimalCount;
    return result + num;
}

int main(void) {
    printf("%d", revert(12345));
    return 0;
}