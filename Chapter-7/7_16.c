// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char* wFace[],
    const char* wSuit[]); // dealing doesn't modify the arrays

int main(void)
{
    // initialize deck array
    unsigned int deck[SUITS][FACES] = { 0 };

    for (int i = 0, count = 1; i < SUITS; i++) {
        for (int e = 0; e < FACES; e++)
            deck[i][e] = count++;
    }
    puts("Before shuffle");
    for (int i = 0; i < SUITS; i++) {
        for (int e = 0; e < FACES; e++)
            printf("%3d ",deck[i][e]);
        puts("");
    }

    srand(time(NULL)); // seed random-number generator
    shuffle(deck); // shuffle the deck
    puts("\nAfter shuffle");
    for (int i = 0; i < SUITS; i++) {
        for (int e = 0; e < FACES; e++)
            printf("%3d ", deck[i][e]);
        puts("");
    }
    // initialize suit array                       
    const char* suit[SUITS] =
    { "Hearts", "Diamonds", "Clubs", "Spades" };

    // initialize face array                   
    const char* face[FACES] =
    { "Ace", "Deuce", "Three", "Four",
     "Five", "Six", "Seven", "Eight",
     "Nine", "Ten", "Jack", "Queen", "King" };

    puts("");
    deal(deck, face, suit); // deal the deck
    return 0;
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{

    for (int i = 0, tmp, row, column; i < SUITS; i++) {
        for (int e = 0; e < FACES; e++) {
            row = rand() % SUITS;
            column = rand() % FACES;
            tmp = wDeck[i][e];
            wDeck[i][e] = wDeck[row][column];
            wDeck[row][column] = tmp;
        }
    }


    //// for each of the cards, choose slot of deck randomly
    //for (size_t card = 1; card <= CARDS; ++card) {
    //    size_t row; // row number
    //    size_t column; // column number

    //    // choose new random location until unoccupied slot found
    //    do {
    //        row = rand() % SUITS;
    //        column = rand() % FACES;
    //    } while (wDeck[row][column] != 0); // end do...while

    //    // place card number in chosen slot of deck
    //    wDeck[row][column] = card;
    //}
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char* wFace[],
    const char* wSuit[])
{
    // deal each of the cards
    int cardDone;
    for (size_t card = 1; card <= CARDS; ++card) {
        cardDone = 0;
        // loop through rows of wDeck
        for (size_t row = 0; row < SUITS; ++row) {
            if (cardDone)
                break;
            // loop through columns of wDeck for current row
            for (size_t column = 0; column < FACES; ++column) {
                // if slot contains current card, display card
                if (wDeck[row][column] == card) {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                        card % 2 == 0 ? '\n' : '\t'); // 2-column format
                    cardDone = 1;
                    break;
                }
            }
        }
    }
}



