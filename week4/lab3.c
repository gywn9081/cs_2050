#include <stdio.h>
#include "lab3.h"

/*
	newBoard
		no Parameters
		returns pointer int to board
		makes an array of size BOARD_SIZE
		stores a hidden score (float) and two int hits; shots
*/
int* newBoard() {
	int *nd_board = malloc((sizeof(int) * (BOARD_SIZE + 2)) + sizeof(float));
	if (nd_board == NULL) {
		return nd_board;
	}
	*((float*)(nd_board)) = 0.0;
	nd_board = (int*)((float*)(nd_board) + 1);
	for (int i = 0; i < (BOARD_SIZE + 2); i++) {
		nd_board[i] = 0;
	}
	nd_board = nd_board + 2;
	return(nd_board);
}


/*
	takeshot
		parameters:
			pointer int to a board
			int index of target cell
		Returns
			int 1 if hit 0 if no live ship in cell
		hits a ship if present in indicated cell and updates hidden values accordingly
*/
int takeShot ( int * board , int cell ) {
	int *openBoard = board - 2;
	float *score = (float*)(openBoard) - 1;
	openBoard[0]++;
	if (board[cell] < 1) { 
		*score = openBoard[1] / openBoard[0];
		return 0;
	}
	board[cell] = -1;
	openBoard[1]++;
	*score = openBoard[1] / openBoard[0];
	return 1;
}


/*
	countRemainingShips
		Parameters
			int pointer to board
		Returns
			count int to number of ships left
		Counts how many living ships are left on the board
*/
int countRemainingShips(int *board) {
	int remain = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i] == 1) {
			remain++;
		}
	}
	return remain;
}


/*
	getShotsTaken
		Parameters
			int pointer to board
		Returns
			int amount of shots taken
		gets the amount of shots taken stored in a hidden value
*/
int getShotsTaken(int *board) {
	int *openBoard = board - 2;
	return(openBoard[0]);
}

/*
	getHits
		Parameter
			int pointer to board
		Returns
			int number of hits
		gets the number of ships that have been hit stored in hidden value
*/
int getHits ( int * board ) {
	int *openBoard = board - 2;
	return (openBoard[1]);
}


/*
	getScore
		parameters
			int pointer to board
		returns
			float of score
		gets score as in hidden parameters
*/
float getScore(int *board) {
	int *openBoard = board - 2;
	float *score = ((float*)openBoard) - 1;
	return *score;
}


/*
	updateScore
		parameters
			int pointer to board
		returns
			nothing
	updates score based on values in hidden values other than score
*/
void updateScore(int *board) {
	int *openBoard = board - 2;
	float *score = ((float*)openBoard) -1;
	*score = openBoard[1] / openBoard[0];
}


/*
	endGame
		Parameters
			int pointer to board
		returns
			nothing
		Frees mem allocated to the board and sets it to NULL
*/
void  endGame(int* nd_board) {
	int *openBoard = nd_board - 2;
	free(((float*)openBoard) - 1);
	nd_board = NULL;
}
