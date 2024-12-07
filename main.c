#include <stdio.h>
#include "gamelogic.h"

int main(void) {
    char board[ROWS][COLS];
    Ship shipArray[4];

    initialiseBoard(board);
    createShips(shipArray);

    printBoard(board);
    
    int numberOfShips = NUMBER_OF_SHIPS;
    int shipChosen = 0;
    char orientation = 0;

    printChooseShipMenu(&numberOfShips, &shipChosen, &orientation, shipArray);



    return 0;
}