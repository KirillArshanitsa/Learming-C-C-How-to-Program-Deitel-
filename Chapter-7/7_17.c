#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DISTACE 70

int hareMotion(void);
int turtleMotion(void);
void printRace(int, int);

void printRace(int harePosition, int turtlePosition){
    int stopPoint;

    if (harePosition == turtlePosition){
        if (harePosition <= DISTACE)
            stopPoint = DISTACE;
        else
            stopPoint = harePosition;

        for (int i = 1 ; i <= stopPoint ; i++){
            if (i == harePosition)
                printf("%s", "OUCH!!!");
            else{
                printf("%s", " ");
            }
        }
    }
    else {
        if (harePosition > turtlePosition)
            if (harePosition >= DISTACE)
                stopPoint = harePosition;
            else
                stopPoint = DISTACE;
        else {
            if (turtlePosition >= DISTACE)
                stopPoint = turtlePosition;
            else
                stopPoint = DISTACE;
        }
        for (int i = 1; i <= stopPoint; i++) {
            if (i == harePosition)
                printf("%s", "H");
            else if (i == turtlePosition)
                printf("%s", "T");
            else {
                printf("%s", " ");
            }
        }
    }
    puts(" ");
}

int turtleMotion(void) {
    int motion = 1 + rand() % 10;
    switch (motion) {
        case (1):
        case (2):
        case (3):
        case (4):
        case (5):
            return 3;
        case (6):
        case (7):
            return -6;
        case (9):
        case (10):
            return 1;
    }
}

int hareMotion(void){
    int motion = 1 + rand() % 10;
    switch(motion){
        case(1):
        case(2):
            return 0;
        case(3):
        case(4):
            return 9;
        case(5):
            return -12;
        case(6):
        case(7):
        case(8):
            return 1;
        case(9):
        case(10):
            return 2;
    }
}

int main(void){
    srand(time(NULL));
    printf("%s", "BANG!!!!!\nANG THE'RE OFF!!!!!");

    int harePosition = 1;
    int turtlePosition = 1;
    printRace(harePosition, turtlePosition);

    while(1){
        harePosition += hareMotion();
        turtlePosition += turtleMotion();
        if (harePosition <= 0 )
            harePosition = 1;
        if (turtlePosition <= 0 )
            turtlePosition = 1;
        printf("Print race: harePosition %d, turtlePosition %d\n", harePosition, turtlePosition);
        printRace(harePosition, turtlePosition);

        if ((harePosition >= 70) && (turtlePosition >= 70)) {
            puts("DRAW!!!");
            break;
        }

        if (harePosition >= 70) {
            printf("Hare wins, Yuch");
            break;
        }
        else if(turtlePosition >= 70) {
            printf("TORTOISE WINS!!!, YUA!!");
            break;
        }
    }

    return 0;
}