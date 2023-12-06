#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Card structure definition */
struct card {
	const char *face;
	const char *suit;
};

typedef struct card Card; /* New type name for struct card */

/* Function prototypes */
void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(void) {
	Card deck[52]; /* Define array of Cards */
	const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six",
						  "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	srand(time(NULL)); /* Randomize */

	fillDeck(deck, face, suit); /* Load the deck with Cards */
	shuffle(deck); /* Put Cards in random order */
	deal(deck); /* Deal all 52 Cards */

	return 0; /* Indicates successful termination */
} /* End main */

/* Place strings into Card structures */
void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]) {
	size_t i; /* Counter */

	/* Loop through wDeck */
	for (i = 0; i < 52; ++i) {
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	} /* End function fillDeck */
}

/* Shuffle cards */
void shuffle(Card * const wDeck) {
	size_t i; /* Counter */
	size_t j; /* Variable to hold random value between 0 - 51 */
	Card temp; /* Define temporary structure for swapping Cards */

	/* Loop through wDeck randomly swapping Cards */
	for (i = 0; i < 52; ++i) {
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	} /* End function shuffle */
}

/* Deal cards */
void deal(const Card * const wDeck) {
	size_t i; /* Counter */

	/* Loop through wDeck */
	for (i = 0; i < 52; ++i) {
		printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 == 0 ? "\n" : "\t");
	} /* End for */
}