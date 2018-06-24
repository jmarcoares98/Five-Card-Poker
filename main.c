#include "header.h"

int main(void)
{
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	Card player_hand[5] = { { 0, 0, 0 } };
	Card dealer_hand[5] = { {0, 0, 0} };

	int player_pts = 0;
	int dealer_pts = 0;
	int yesorno = 0;
	int rounds = 1;
	int wins = 0;

	srand((unsigned)time(NULL)); /* seed random-number generator */

	welcome_screen();

	while(rounds < 10) 
	{
		shuffle(deck);
		printf("Players Hand\n\n");
		deal(deck, face, suit, player_hand, 5, 1, 0);
		deal_computer(deck, face, suit, dealer_hand, 5, 6, 0);
		printf("\n=======================================\n");
		printf("You can only switch the cards out once\n");
		printf("Do you want to switch cards? [1]YES or [0]NO\n");
		scanf("%d", &yesorno);
		if (yesorno == 1)
		{
			change_cards(deck, face, suit, player_hand);
		}
		if (yesorno == 1 || yesorno == 0)
		{
			system("pause");
			system("cls");
			for (int i = 0; i < 5; i++)
			{
				printf("%d) ", i + 1);
				printf("%5s of %-8s%c", face[player_hand[i].col_index],
					suit[player_hand[i].row_index], (i + 1) % 5 == 0 ? '\n' : '\t');
			}
			printf("\n");
		}

		dealer_pts = evaluate_computer_cards(dealer_hand);
		if (dealer_pts <= 2)
		{
			change_computer_cards(deck, face, suit, player_hand, 2);
		}
		else if (dealer_pts > 3)
		{
			printf("Dealer will not change cards\n");
		}

		printf(" . . . SHOW CARDS!!!\n");
		system("pause");
		system("cls");
		printf("Dealer's Cards\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d) ", i + 1);
			printf("%5s of %-8s%c", face[dealer_hand[i].col_index],
				suit[dealer_hand[i].row_index], (i + 1) % 5 == 0 ? '\n' : '\t');
		}
		printf("\n=======================================\n");
		printf("Player's Cards\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d) ", i + 1);
			printf("%5s of %-8s%c", face[player_hand[i].col_index],
				suit[player_hand[i].row_index], (i + 1) % 5 == 0 ? '\n' : '\t');
		}
		printf("\n=======================================\n");
		printf("Dealer has: \n");
		dealer_pts = evaluate_cards(dealer_hand);
		printf("Player Has: \n");
		player_pts = evaluate_cards(player_hand);

		wins = determine_winner(player_pts, dealer_pts, player_hand, dealer_hand);
		system("pause");
		system("cls");
		rounds++;
		re_shuffle(deck);
	} 

	if (rounds == 10)
	{
		system("pause");
		system("cls");
		printf("You have won %d out of 10 games\n!", wins);
	}

	return 0;
}
