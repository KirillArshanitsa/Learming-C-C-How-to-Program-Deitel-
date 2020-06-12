#include <stdio.h>

void drawSquare(int);

void drawSquare(int num) {
    for (int hight = num; hight > 0; hight--) {
        for (int lenght = num; lenght > 0; lenght--)
            printf("*");
        puts("");
    }
}

int main(void) {
    int side = 5;
    //puts("Enter side for square");
    //scanf_s("%d", &side);
    drawSquare(side);
    return 0;
}