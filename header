#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 5


typedef struct card
{
	// tracking positions of cards in deck
	int row_index;
	int col_index;
	int card_num;
}Card;

typedef struct deck
{
	const char *suit[4];
	const char *face[13];
}Deck;

void welcome_screen();
void shuffle(int wDeck[][13]);
void re_shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[],
	const char *wSuit[], Card hand[], int num_draw, int card_num, int count);
void deal_computer(const int wDeck[][13], const char *wFace[],
	const char *wSuit[], Card computer[], int num_draw, int card_num, int count);
int high_card(Card hand[]);
int pair(Card hand[]);
int two_pair(Card hand[]);
int three_of_a_kind(Card hand[]);
int straight(Card hand[]);
int flush(Card hand[]);
int full_house(Card hand[]);
int four_of_a_kind(Card hand[]);
int straight_flush(Card hand[]);
int evaluate_cards(Card hand[]);
int determine_winner(int player_pts, int dealer_pts, Card player[], Card dealer[]);
void change_cards(const int Deck[][13], const char *Face[],
	const char *Suit[], Card hand[]);
int evaluate_computer_cards(Card hand[]);
