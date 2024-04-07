#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* This function simulates the coin-toss game for two players.
The first two arguments are character strings of length 3,
where each character is H or T. If one of the strings does not
satisfy the requirements, the function returns a nonzero number
to signify an error, otherwise it returns 0 to signify there
were no errors. A sequence of coin tosses is then simulated
until the sequence of one of the players is encountered.
The number of the winning player will be stored at the
location specified by winner and the number of tosses
performed will be stored in numTosses. */

int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses) {
	char tlat[2] = {'t', 'h'};
	int tosses[4] = {0};
	srand(time(NULL));
	// Init flips
	for (int i = 0; i < 4; i++) {
		//tosses[i] = 0;
		tosses[i] = rand() % 2;
		printf("%d\n", tosses[i]);
	}
	for (int i = 0; ; i++) {
		printf("sequence is %d %d %d \n", tosses[(i % 4)], tosses[(i + 1) % 4], tosses[(i + 2) % 4]);
		if (tlat[tosses[(i % 4)]] == player1[0] && tlat[tosses[(i + 1) % 4]] == player1[1] && tlat[tosses[(i + 2) % 4]] == player1[2]) {
			*winner = 1;
			*numTosses = i + 3;
			return 0;
		}
		if (tlat[tosses[(i % 4)]] == player2[0] && tlat[tosses[(i + 1) % 4]] == player2[1] && tlat[tosses[(i + 2) % 4]] == player2[2]) {
			*winner = 2;
			*numTosses = i + 3;
			return 0;
		}
		tosses[i % 4] = rand() % 2;
	}
}


