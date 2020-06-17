// Fig. 5.14: fig05_14.c
// Simulating the game of craps.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

int rollDice(void); // function prototype
int runGame();

int main(void)
{
    // randomize random number generator using current time
    srand(time(NULL));

    int bankBalance = 1000;
    int bet;

    while (bankBalance) {
        do {
            puts("Enter your bet");
            scanf_s("%d", &bet);
        } while (bet > bankBalance);

        if (runGame())
            bankBalance += bet;
        else
            bankBalance -= bet;
        printf("Your balance is %d\n", bankBalance);
    }
    puts("Your money is over.");
    return 0;
}

// roll dice, calculate sum and display results
int rollDice(void)
{
    int die1 = 1 + (rand() % 6); // pick random die1 value
    int die2 = 1 + (rand() % 6); // pick random die2 value

    // display results of this roll
    printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
    return die1 + die2; // return sum of dice
}


int runGame(void) {

    int myPoint; // player must make this point to win
    enum Status gameStatus; // can contain CONTINUE, WON, or LOST

    int sum = rollDice(); // first roll of the dice
    // determine game status based on sum of dice
    switch (sum) {
            // win on first roll
        case 7: // 7 is a winner
        case 11: // 11 is a winner          
            gameStatus = WON;
            break;

            // lose on first roll
        case 2: // 2 is a loser
        case 3: // 3 is a loser
        case 12: // 12 is a loser
            gameStatus = LOST;
            break;

            // remember point
        default:
            gameStatus = CONTINUE; // player should keep rolling
            myPoint = sum; // remember the point
            printf("Point is %d\n", myPoint);
            break; // optional
    }

    // while game not complete
    while (CONTINUE == gameStatus) { // player should keep rolling
        sum = rollDice(); // roll dice again

        // determine game status
        if (sum == myPoint) { // win by making point
            gameStatus = WON;
        }
        else {
            if (7 == sum) { // lose by rolling 7
                gameStatus = LOST;
            }
        }
    }

    puts("");
    switch (1 + rand() % 3) {
        case 1:
            puts("Going all in? Yes?");
            break;
        case 2:
            puts("Enough, is it time for you to exchange chips?");
            break;
        case 3:
            puts("Take a chance!");
            break;
    }
    puts("");

    // display won or lost message
    if (WON == gameStatus) { // did player win?
        puts("Player wins");
        return 1;
    }
    else { // player lost
        puts("Player loses");
        return 0;
    }

}
