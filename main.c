#include <stdio.h>
#include "gamelogic.h"

int main(void) {
    char board[ROWS][COLS];
    Ship shipArray[4];

    initialiseBoard(board);
    createShips(shipArray);
   
    int numberOfShips = NUMBER_OF_SHIPS;
    int shipChosen = 0;
    char orientation = 0;

    printShipMenuAndPlaceShip(&numberOfShips, &shipChosen, &orientation, shipArray);
    printBoard(board);
    placeShip(board, &orientation, shipArray, &shipChosen);
    printBoard(board);

    return 0;
}