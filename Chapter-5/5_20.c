#include <stdio.h>

void drawSquare(int);

void drawSquare(int num, char fillCharacter) {
    for (int hight = num; hight > 0; hight--) {
        for (int lenght = num; lenght > 0; lenght--)
            printf("%c", fillCharacter);
        puts("");
    }
}

int main(void) {
    int side = 7;
    char fillCharacter = '#';
    //puts("Enter side for square");
    //scanf_s("%d", &side);
    drawSquare(side, fillCharacter);
    return 0;
}