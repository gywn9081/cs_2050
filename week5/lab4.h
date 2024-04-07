#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 32

typedef struct {
    int shots;
    int hits;
    float score;
    int arena[BOARD_SIZE];
} GameBoard;


GameBoard * newBoard();

int takeShot(GameBoard *board, int cell);

int countFreeCells(GameBoard *board);

int getShotsTaken(GameBoard *board);

int getHits(GameBoard *board);

float getScore(GameBoard *board);

int placeShip(GameBoard *board, int cell);

void endGame(GameBoard *board);

