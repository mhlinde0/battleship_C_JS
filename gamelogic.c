#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "gamelogic.h"

void initialiseBoard(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = '~';
        }
    }
}

void printBoard (char board[ROWS][COLS]){
    printf("\n");

    for(int i = 0; i < ROWS; i++){
        // Udskriv række-nr og felter
        for(int j = 0; j < COLS; j++){
            if(j == 0){
                printf("%d   ", (ROWS-1-i));  // Rækkenumre i starten af hver række
            }
            printf("%c ", board[i][j]);
        }
        printf("\n");  // Ny linje efter hver række

        // Udskriv kolonnenumre
        if(i == (ROWS-1)){
            printf("\n");
            printf("    ");
            for(int k = 0; k < COLS; k++){
                printf("%d ", k);
            }
            printf("\n");
        }
    }
}

void createShips(Ship shipArray[4]) {
    shipArray[0] = (Ship){"Carrier", 5, 1, {{0, 0}}};
    shipArray[1] = (Ship){"Battleship", 4, 2, {{0, 0}}};
    shipArray[2] = (Ship){"Submarine", 3, 3, {{0, 0}}};
    shipArray[3] = (Ship){"Patrol Boat", 2, 4, {{0, 0}}};
}

void printShipMenuAndPlaceShip(int* numberOfShips, int* shipChosen, char* orientation, Ship shipArray[4]){
    //print ship menu
    printf("\nLedige skibe:\n");
    printf("Nr.    Navn            Antal tilbage     Længde:\n");
    for(int i = 1; i <= *numberOfShips; i++){
        printf("%d:     %-16s%-18d%-7d\n", i, shipArray[i-1].name, shipArray[i-1].amountLeft, shipArray[i-1].length);   
    }
    
    
    //get ship from user
    while(true){
        printf("\nIndtast skib at placere (1-4): ");
        if (scanf("%d", shipChosen) != 1 || *shipChosen < 1 || *shipChosen > 4) {
            printf("Ugyldigt valg! Vælg et skib mellem 1 og 4.\n");
            while (getchar() != '\n');
            continue; 
        }
        *shipChosen -= 1;
        break;
    }

    //get orientation from user
    while(true){
        printf("Vælg orientering (v=vandret, l=lodret): ");
        while (getchar() != '\n');
        if (scanf("%c", orientation) != 1 || (*orientation != 'v' && *orientation != 'l')) {
            printf("Ugyldigt valg! Vælg 'v' for vandret eller 'l' for lodret.\n");
            continue;
        }
        break;
    }
    if(*orientation == 'v') printf("Vandret %s valgt.\n", shipArray[*shipChosen].name);
    if(*orientation == 'l') printf("Lodret %s valgt.\n", shipArray[*shipChosen].name);

}

void placeShip(char board[ROWS][COLS], char *orientation, Ship shipArray[4], int *shipChosen){
    //get coords from user
    printf("\nVælg koordinat for placering af skib.\n(Skriv: \"x,y\") (NB. V går til højre fra koordinat, L går ned): ");

    //get x and y coords from user
    int xCoord = 0, yCoord = 0;

    while(true){
        while (getchar() != '\n');
        char buffer[8] = {0};
        
        // Checks for null inputs
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input! Try again: ");
            continue;
        }
        
        buffer[strcspn(buffer, "\n")] = '\0';

        // Checks for empty inputs
        if (strlen(buffer) == 0) {
            printf("Input can't be empty! Try again: ");
            continue;
        }

        if (sscanf(buffer, "%d,%d", &xCoord, &yCoord) != 2) {
            printf("Invalid input! Try again: ");
            continue;
        } 
        
        break;
    }

    
    int mapping[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; 

    /* mapping bruges til at konvertere yCoord til korrekt index i board, da input og board-indekser er "invers" eg. input 8 = indeks 2.
    Ved 'v': Start ved xCoord og marker skibets længde mod højre i samme row. yCoord (row) er fast og bruges via mapping.
    Ved 'l': Start ved yCoord og marker skibets længde nedad i samme kolonne. xCoord (kolonne) er fast. */

    if(*orientation == 'v'){
        for(int i = xCoord; i < xCoord + shipArray[*shipChosen].length; i++){
            board[mapping[yCoord]][i] = 'S';
        }
    }
    if(*orientation == 'l') {
        for(int i = mapping[yCoord]; i < (mapping[yCoord] + shipArray[*shipChosen].length); i++){
            board[i][xCoord] = 'S';
        }
    }
}