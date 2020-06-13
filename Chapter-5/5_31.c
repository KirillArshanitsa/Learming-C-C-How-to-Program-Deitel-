#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int flip(void);

unsigned int flip(void) {
    return rand() % 2;
}

int main(void) {
    unsigned int Heads = 0;
    unsigned int Tail = 0;
    unsigned int flipResult;
    srand(time(NULL));
    for (int i = 0; i <= 100; i++) {
        switch (flipResult = flip()) {
        case 1:
            puts("Heads");
            Heads++;
            break;
        case 0:
            puts("Tail");
            Tail++;
            break;
        default:
            puts("Error");
        }
    }
    printf("Tail count is %u, Heads count is %u", Tail, Heads);
    return 0;
}