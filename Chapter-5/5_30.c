#include <stdio.h>

unsigned int qualityPoints(unsigned int);

unsigned int qualityPoints(unsigned int rating) {
    if (90 <= rating & rating <= 100)
        return 4;
    else if (80 <= rating & rating <= 89)
        return 3;
    else if (70 <= rating & rating <= 79)
        return 2;
    else if (60 <= rating & rating <= 69)
        return 1;
    else if (60 > rating)
        return 0;
}

int main(void) {
    printf("Average rating is %d", qualityPoints(73));
    return 0;
}