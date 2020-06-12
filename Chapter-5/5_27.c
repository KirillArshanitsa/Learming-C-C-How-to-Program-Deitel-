#include <stdio.h>

void simple(unsigned int);

void simple(unsigned int num) {
    for (int i = 2; i < num ; i++) {
        if (num % i == 0) {
            //printf("Nuber %d is not simple\n", num);
            return;
        }
    }
    printf("Nuber %d is simple\n", num);
}

int main(void) {
    for (unsigned i = 1; i <= 10000; i++) {
        simple(i);
    }
    return 0;
}