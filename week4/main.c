#include <stdio.h>
#include "lab3.h"

int main() {



	int* nd_board = NULL;
	nd_board = newBoard();
	

	for (int i = 0; i < BOARD_SIZE; i++) {
		nd_board[i] = 1;
		printf("%lf", getScore(nd_board));
		takeShot(nd_board, i);
	}


	printf("ships: %d\n", countRemainingShips(nd_board));
	printf("Shots: %d\n", getShotsTaken(nd_board));
	printf("Hits: %d\n", getHits(nd_board));


	int *openBoard = nd_board - 2;
	printf("%lf", ((float*)(openBoard))[-1]);
	endGame(nd_board);




	return 0;
}
