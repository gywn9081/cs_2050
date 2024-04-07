#include <stdio.h>
#include "lab4.h"

int main() {

	GameBoard *gBoard = newBoard();
	printf("free cells: %d\n", countFreeCells(gBoard));
	printf("shots taken: %d\n", getShotsTaken(gBoard));
	printf("hits: %d\n", getHits(gBoard));
	printf("score: %lf\n", getScore(gBoard));




	printf("ship placed: %d\n", placeShip(gBoard, 30));
	printf("ship placed: %d\n", placeShip(gBoard, 30));
	printf("ship at 30 %d\n", gBoard->arena[30]);
	printf("shot ship: %d\n", takeShot(gBoard, 30));
	printf("shot ship: %d\n", takeShot(gBoard, 30));
	printf("ship at 30 %d\n", gBoard->arena[30]);
	printf("shot ship: %d\n", takeShot(gBoard, 0));


	printf("free cells: %d\n", countFreeCells(gBoard));
	printf("shots taken: %d\n", getShotsTaken(gBoard));
	printf("hits: %d\n", getHits(gBoard));
	printf("score: %lf\n", getScore(gBoard));




	endGame(gBoard);
	return 0;
}
