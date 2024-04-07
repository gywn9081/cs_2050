#include <stdio.h>
#include "lab4.h"


/*
	newBoard()
		Returns pointer to GameBoard
			NULL if error
		Sets all fields to init values
*/

/*
	This must be included for compilation with -Wmissing-prototypes
	Don't know if you would like us to include this since not modifying header
	GameBoard* newBoard(void);
*/

GameBoard* newBoard() {
	GameBoard *gb = malloc(sizeof(GameBoard));
	if (gb == NULL) {
		return gb;
	}

	gb->shots = 0;
	gb->hits = 0;
	gb->score = 0.0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		gb->arena[i] = 0;
	}

	return gb;
}


/*
	takeShot
		Parameters
			board pointer to GameBoard
			cell index of item
		Takes shot and updates values accordingly
		Returns int
			1 if hit live ship
			0 if dead ship or empty cell
*/
int takeShot(GameBoard* board, int cell) {
	int hit = 0;
	if (board->arena[cell] == 1) {
		board->hits++;
		board->arena[cell] = -1;
		hit = 1;
	}
	board->shots++;
	board->score = ((float)board->hits)/((float)board->shots);

	return hit;
}

/*
	countFreeCells
		Parameters
			board pointer to GameBoard
		Returns
			number of empty cells int
*/
int countFreeCells(GameBoard* board) {
	int ecells = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board->arena[i] == 0) {
			ecells++;
		}
	}
	return ecells;
}


/*
	getShotsTaken
		Parameters
			board pointer to GameBoard
		Returns
			number of shots taken int
*/
int getShotsTaken(GameBoard* board) {
	int tshots = board->shots;
	return tshots;
}


/*
	getHits
		Parameters
			board pointer to GameBoard
		Returns
			number of hits int
*/
int getHits(GameBoard* board) {
	int thits = board->hits;
	return thits;
}


/*
	getScore
		Parameters
			board pointer to GameBoard
		Returns
			score float

*/
float getScore(GameBoard* board) {
	float tscore = board->score;
	return tscore;
}



/*
	placeShip
		Parameters
			board pointer to GameBoard
			cell int index of item
		Returns
			1 if ship is placed succesfully in empty cell
			0 if cell was not empty
		Updates arena to have ship in place if cell empty
*/
int placeShip(GameBoard* board, int cell) {
	if (board->arena[cell] == 0) {
		board->arena[cell] = 1;
		return 1;
	}
	return(0);
}


/*
	endGame
		Frees mem alloc to board
*/
void endGame(GameBoard* board) {
	free(board);
	board = NULL;
}










