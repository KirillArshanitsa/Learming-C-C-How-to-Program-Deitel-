#include <stdio.h>

void perfect(unsigned int);

void perfect(unsigned int num) {
    for (int i = 2, sum = 1; sum < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
        if (sum == num) {
            printf("\n%d is perfect, ", num);
            for (int i = 1, sum = 0; sum != num & sum < num; i++) {
                if (num % i == 0) {
                    sum += i;
                    printf("%d ", i);
                }
            }
            break;
        }
    }
}

int main(void) {
    for (unsigned i = 1; i <= 10000; i++) {
        perfect(i);
    }

    return 0;
}