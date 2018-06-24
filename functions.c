#include "header.h"

//Given code
/* shuffle cards in deck */

void welcome_screen()
{
	printf("==========WELCOME TO 5-CARD DRAW POKER==========\n");
	printf("\n              10 ROUNDS OF POKER\n");
	printf("             YOU VS. THE COMPUTER!\n");
	printf("\n================================================\n");
	printf("\n           LETS PLAY SOME POKER BOI!!\n\n");
	system("pause");
	system("cls");
}

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}

	printf("Shuffling . . .\n");
	system("pause");
	system("cls");
}

void re_shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		for (row = 0; row < 4; row++)
		{
			for (column = 0; column < 13; column++)
			{
				wDeck[row][column] = 0;
			}
		}
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char *wFace[],
	const char *wSuit[], Card hand[], int num_draw, int card_num, int count)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = card_num; card < card_num + num_draw; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					hand[count].row_index = row;
					hand[count].col_index = column;
					hand[count].card_num = card;
					++count;
					//ternary operator ? :
					printf("%d) ", count);
					printf("%5s of %-8s%c", wFace[column],
						wSuit[row], card % 5 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

/* deal cards in deck */
void deal_computer(const int wDeck[][13], const char *wFace[],
	const char *wSuit[], Card computer[], int num_draw, int card_num, int count)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	do {
		/* deal each of the 52 cards */
		for (card = card_num; card < card_num + num_draw; card++)
		{
			/* loop through rows of wDeck */
			for (row = 0; row <= 3; row++)
			{
				/* loop through columns of wDeck for current row */
				for (column = 0; column <= 12; column++)
				{
					/* if slot contains current card, display card */
					if (wDeck[row][column] == card)
					{
						computer[count].row_index = row;
						computer[count].col_index = column;
						computer[count].card_num = card;
						++count;
					}
				}
			}
		}
	} while (wDeck[row][column] == 0);
}


int high_card(Card hand[])
{
	int check = 0;

	for (int i = 0; i < 5; i++)
	{
		if (hand[i].col_index == 0 || hand[i].col_index > 8)
		{
			check = 1;
		}
	}
	return check;
}

int pair(Card hand[])
{
	int i = 0;
	//local arrays
	int rows[4] = { 0 };
	int cols[13] = { 0 };
	int check = 0;

	for (i = 0; i < 5; i++)
	{
		rows[hand[i].row_index]++;
		cols[hand[i].col_index]++;
	}

	for (int j = 0; j < 13; j++)
	{
		if (cols[j] == 2)
		{
			check = 2;
		}
	}

	return check;
}

int two_pair(Card hand[])
{
	int i = 0;
	//local arrays
	int rows[4] = { 0 };
	int cols[13] = { 0 };
	int check = 1;

	for (i = 0; i < 5; i++)
	{
		rows[hand[i].row_index]++;
		cols[hand[i].col_index]++;
	}

	for (int j = 0; j < 13; j++)
	{
		if (cols[j] == 2)
		{
			check += 1;
		}
	}

	return check;
}

int three_of_a_kind(Card hand[])
{
	int i = 0;
	//local arrays
	int rows[4] = { 0 };
	int cols[13] = { 0 };
	int check = 0;

	for (i = 0; i < 5; i++)
	{
		rows[hand[i].row_index]++;
		cols[hand[i].col_index]++;
	}

	for (int j = 0; j < 13; j++)
	{
		if (cols[j] == 3)
		{
			check = 4;
		}
	}

	return check;
}

int straight(Card hand[])
{
	int i = 0;
	//local arrays
	int rows[4] = { 0 };
	int cols[13] = { 0 };
	int check = 0;

	for (i = 0; i < 5; i++)
	{
		rows[hand[i].row_index]++;
		cols[hand[i].col_index]++;
	}

	for (int j = 0; j < 8; j++)
	{
		if ((cols[j] == 1) && (cols[j + 1] == 1) && (cols[j + 2] == 1) && (cols[j + 3] == 1) && (cols[j + 4] == 1))
		{
			check = 5;
		}
	}
	return check;
}

int flush(Card hand[])
{
	int i = 0;
	//local arrays
	int rows[4] = { 0 };
	int cols[13] = { 0 };
	int check = 0;

	for (i = 0; i < 5; i++)
	{
		rows[hand[i].row_index]++;
		cols[hand[i].col_index]++;
	}

	for (int j = 0; j < 4; j++)
	{
		if (rows[j] == 5)
		{
			check = 6;
		}
	}

	return check;
}

int full_house(Card hand[])
{
	int i = 0;
	//local arrays
	int rows[4] = { 0 };
	int cols[13] = { 0 };
	int check = 0;
	int three = 0;
	int pair = 2;

	for (i = 0; i < 5; i++)
	{
		rows[hand[i].row_index]++;
		cols[hand[i].col_index]++;
	}

	for (int j = 0; j < 13; j++)
	{
		if (cols[j] == 3)
		{
			three = 1;
		}
		if (cols[j] == 2)
		{
			pair = 1;
		}
	}

	if ((three == 1) && (pair == 1))
	{
		check = 7;
	}

	return check;
}

int four_of_a_kind(Card hand[])
{
	int i = 0;
	//local arrays
	int rows[4] = { 0 };
	int cols[13] = { 0 };
	int check = 0;

	for (i = 0; i < 5; i++)
	{
		rows[hand[i].row_index]++;
		cols[hand[i].col_index]++;
	}

	for (int j = 0; j < 13; j++)
	{
		if (cols[j] == 4)
		{
			check = 8;
		}
	}

	return check;
}

int straight_flush(Card hand[])
{
	int i = 0;
	//local arrays
	int rows[4] = { 0 };
	int cols[13] = { 0 };
	int straight = 0;
	int flush = 0;
	int check = 0;

	for (i = 0; i < 5; i++)
	{
		rows[hand[i].row_index]++;
		cols[hand[i].col_index]++;
	}

	for (int j = 0; j < 8; j++)
	{
		if ((cols[j] == 1) && (cols[j + 1] == 1) && (cols[j + 2] == 1) && (cols[j + 3] == 1) && (cols[j + 4] == 1))
		{
			straight = 1;
		}
	}

	for (int k = 0; k < 4; k++)
	{
		if (rows[k] == 5)
		{
			flush = 1;
		}
	}

	if ((straight == 1) && (flush == 1))
	{
		check = 9;
	}
	return check;
}


int evaluate_cards(Card hand[])
{
	int combo = 0;
	int points = 0;
	
	switch (combo)
	{
	case 0:
		points = straight_flush(hand);
		if (points != 0)
		{
			printf("STRAIGHT FLUSH!!!!\n");
			break;
		}
	case 1:
		points = four_of_a_kind(hand);
		if (points != 0)
		{
			printf("FOUR OF A KIND!!\n");
			break;
		}
	case 2:
		points = full_house(hand);
		if (points != 0)
		{
			printf("FULL HOUSE!!!\n");
			break;
		}
	case 3:
		points = flush(hand);
		if (points != 0)
		{
			printf("FLUSH!!\n");
			break;
		}
	case 4:
		points = straight(hand);
		if (points != 0)
		{
			printf("STRAIGHT!\n");
			break;
		}
	case 5:
		points = three_of_a_kind(hand);
		if (points != 0)
		{
			printf("Three of a Kind!!\n");
			break;
		}
	case 6:
		points = two_pair(hand);
		if (points == 3)
		{
			printf("TWO PAIR!\n");
			break;
		}
	case 7:
		points = pair(hand);
		if (points != 0)
		{
			printf("PAIR!!\n");
			break;
		}
		combo++;
	case 8:
		points = high_card(hand);
		if (points != 0)
		{
			printf("HIGH CARD!!\n");
			break;
		}
	}

	if (points == 0)
	{
		printf("HAS BAD CARDS!\n");
	}
	return points;
}

int determine_winner(int player_pts, int dealer_pts, Card player[], Card dealer[])
{
	int wins = 0;
	int player_cards[13] = { 0 };
	int dealer_cards[13] = { 0 };
	int player_hand[5] = { 0 };
	int dealer_hand[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		player_cards[player[i].col_index]++;
		dealer_cards[dealer[i].col_index]++;
	}

	for (int j = 0; j < 5; j++)
	{
		player_hand[j] = player[j].col_index;
		dealer_hand[j] = dealer[j].col_index;
	}
	if (player_pts > dealer_pts)
	{
		printf("Player WINS!!!\n");
		wins = 1;
	}

	if (player_pts < dealer_pts)
	{
		printf("Dealer WINS!!!\n");
	}

	if (player_pts == dealer_pts)
	{
		for (int k = 0; k < 5; k++)
		{
			if (player_hand[k] > dealer_hand[k])
			{
				printf("Player has better cards!\n");
				printf("Player wins!\n");
				wins = 1;
				break;
			}
			if (player_hand[k] < dealer_hand[k])
			{
				printf("Dealer has better cards!\n");
				printf("Dealer wins!\n");
				break;
			}
		}
	
	}
	return wins;
}

void change_cards(const int Deck[][13], const char *Face[],
	const char *Suit[], Card hand[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int count = 0;
	int cards = 0;
	int ask = 0, ask1 = 0, ask2 = 0, ask3 = 0, ask4 = 0;

	printf("Do you want to switch out Card 1? [1]YES or [0]NO\n");
	scanf("%d", &ask);
	if (ask == 1)
	{
		printf("You got:\n");
		deal(Deck, Face, Suit, hand, 1, 11, 0);
	}
	if (ask == 1 || ask == 0)
	{
		printf("\nDo you want to switch out Card 2? [1]YES or [0]NO\n");
		scanf("%d", &ask);
		if (ask == 1)
		{
			printf("You got:\n");
			deal(Deck, Face, Suit, hand, 1, 12, 1);
		}
	}
	printf("\nDo you want to switch out Card 3? [1]YES or [0]NO\n");
	scanf("%d", &ask);
	if (ask == 1)
	{
		printf("You got:\n");
		deal(Deck, Face, Suit, hand, 1, 13, 2);
	}
	printf("\nDo you want to switch out Card 4? [1]YES or [0]NO\n");
	scanf("%d", &ask);
	if (ask == 1)
	{
		printf("You got:\n");
		deal(Deck, Face, Suit, hand, 1, 14, 3);
	}
	printf("\nDo you want to switch out Card 5? [1]YES or [0]NO\n");
	scanf("%d", &ask);
	if (ask == 1)
	{
		printf("You got:\n");
		deal(Deck, Face, Suit, hand, 1, 15, 4);
	}
}

int evaluate_computer_cards(Card hand[])
{
	int combo = 0;
	int points = 0;

	switch (combo)
	{
	case 0:
		points = straight_flush(hand);
		if (points != 0)
		{
			break;
		}
	case 1:
		points = four_of_a_kind(hand);
		if (points != 0)
		{
			break;
		}
	case 2:
		points = full_house(hand);
		if (points != 0)
		{
			break;
		}
	case 3:
		points = flush(hand);
		if (points != 0)
		{
			break;
		}
	case 4:
		points = straight(hand);
		if (points != 0)
		{
			break;
		}
	case 5:
		points = three_of_a_kind(hand);
		if (points != 0)
		{
			break;
		}
	case 6:
		points = two_pair(hand);
		if (points == 3)
		{
			break;
		}
	case 7:
		points = pair(hand);
		if (points != 0)
		{
			break;
		}
		combo++;
	case 8:
		points = high_card(hand);
		if (points != 0)
		{
			break;
		}
	}

	return points;
}

void change_computer_cards(const int Deck[][13], const char *Face[],
	const char *Suit[], Card computer[], int cards)
{
	int random = 0;
	random = rand() % 3;
	printf("Computer is changing cards . . .\n");
	deal_computer(Deck, Face, Suit, computer, cards, 16, random);
}
