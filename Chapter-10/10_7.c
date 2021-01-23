#include <stdlib.h>
#include <stdio.h>

#define CARDS 52

// bitCard structure definition with bit fields
struct bitCard {
    unsigned int face : 4; // 4 bits; 0-15
    unsigned int suit : 2; // 2 bits; 0-3
    unsigned int color : 1; // 1 bit; 0-1
};

typedef struct bitCard Card; // new type name for struct bitCard

void fillDeck(Card * const wDeck); // prototype
void deal(const Card * const wDeck, const char *face[],  const char *suit[]); // prototype
void shuffle(Card * const wDeck );

int main(void)
{
    Card deck[CARDS]; // create array of Cards

    // initialize array of pointers
    const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
                           "Six", "Seven", "Eight", "Nine", "Ten",
                           "Jack", "Queen", "King"};

    // initialize array of pointers
    const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

    fillDeck(deck);
    shuffle(deck);
    deal(deck, face, suit);
}

// initialize Cards
void fillDeck(Card * const wDeck)
{
    // loop through wDeck
    for (size_t i = 0; i < CARDS; ++i) {
        wDeck[i].face = i % (CARDS / 4);
        wDeck[i].suit = i / (CARDS / 4);
        wDeck[i].color = i / (CARDS / 2);
    }
}


void shuffle(Card * const wDeck)
{
    // loop through wDeck randomly swapping Cards
    for (size_t i = 0; i < CARDS; ++i) {
        size_t j = rand() % CARDS;
        Card temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

// output cards in two-column format; cards 0-25 indexed with
// k1 (column 1); cards 26-51 indexed with k2 (column 2)
void deal(const Card * const wDeck, const char *face[],  const char *suit[])
{
    printf("%-6s%s%25s %s\n", "Color", "Card", "Color", "Card");

    // loop through wDeck
    for (size_t k1 = 0, k2 = k1 + 26; k1 < CARDS / 2; ++k1, ++k2) {
        printf("%-6u%-6sof %-15s",
               wDeck[k1].color, face[wDeck[k1].face], suit[wDeck[k1].suit]);
        printf("%-6u%-6sof %s\n",
               wDeck[k2].color, face[wDeck[k2].face], suit[wDeck[k2].suit]);
    }
}



