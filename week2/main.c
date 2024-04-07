#include <stdio.h>
#include "helper.h"

// Heads == 1, Tails == 0
int main() {
	char player1[3] = {'h', 'h', 't'};
	char player2[3] = {'t', 'h', 'h'};
	int coinFlips = 0;
	int winner;

	int eCheck = coinTossGame(player1, player2, &winner, &coinFlips);
	if (eCheck) {
		printf("An error occured");
		return 1;
	}
	if (winner == 1) {
		printf("\n Alice is the winner after %d tosses", coinFlips);
	} else {
		printf("\n Bob is the winner after %d tosses", coinFlips);
	}
}
