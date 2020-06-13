#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessNumber(void);

void checkMultiplicationTable(void) {
    int guessNumber;
    int countTrying = 0;
    int number = 1 + rand() % 1000;
    printf("%s", "I have a number 1-1000\nCan you guess him?\nPlease enter you first number.\n");
    scanf("%d", &guessNumber);
    ++countTrying;
    if (guessNumber == number) {
        printf("Excelent! You guessed the number!\nTry again?\n");
        return;
    }
    else if (guessNumber > number) {
        printf("Too big number, try again\n");
    }
    else {
        printf("A little little number, try again\n");
    }
    while (guessNumber != number) {
        printf("%s", "Please enter number\n");
        scanf("%d", &guessNumber);
        ++countTrying;

        if (guessNumber > number) {
            printf("Too big number\n");
        }
        else if (guessNumber < number) {
            printf("A little little number\n");
        }
    }
    if (countTrying <= 10)
        printf("You know the secret.");
    else
        printf("You can guess faster.");
}


int main(void) {
    srand(time(NULL));
    checkMultiplicationTable();
    return 0;
}