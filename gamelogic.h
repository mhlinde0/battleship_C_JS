#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#define ROWS 10
#define COLS 10
#define NUMBER_OF_SHIPS 4
#define MAX_SHIP_LENGTH 5

typedef struct Coordinates
{
    int x;
    int y;
} Coordinates;

typedef struct Ship
{
    char name[12];
    int length;
    int amountLeft;
    Coordinates boardPosition[MAX_SHIP_LENGTH];
} Ship;

void initialiseBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
void createShips(Ship shipArray[4]);
void printChooseShipMenu(int* numberOfShips, int* shipChosen, char* orientation, Ship shipArray[4]);
void placeShip(char board[ROWS][COLS], int row, int col);

#endif
