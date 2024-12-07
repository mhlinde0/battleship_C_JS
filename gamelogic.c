#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "gamelogic.h"

void initialiseBoard(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = '?';
        }
    }
}

void printBoard (char board[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        // Udskriv kolonnenumre
        if(i == 0){
            printf("    ");
            for(int k = 0; k < COLS; k++){
                printf("%d ", k);
            }
            printf("\n\n");
        }

        // Udskriv række-nr og felter
        for(int j = 0; j < COLS; j++){
            if(j == 0){
                printf("%d   ", i);  // Rækkenumre i starten af hver række
            }
            printf("%c ", board[i][j]);
        }
        printf("\n");  // Ny linje efter hver række
    }
}

void createShips(Ship shipArray[4]) {
    shipArray[0] = (Ship){"Carrier", 5, 1, {{0, 0}}};
    shipArray[1] = (Ship){"Battleship", 4, 2, {{0, 0}}};
    shipArray[2] = (Ship){"Submarine", 3, 3, {{0, 0}}};
    shipArray[3] = (Ship){"Patrol Boat", 2, 4, {{0, 0}}};
}

void chooseAndPlaceShip(int* numberOfShips, int* shipChosen, char* orientation, Ship shipArray[4]){
    //print ship menu
    printf("\nLedige skibe:\n");
    printf("Nr.    Navn            Antal tilbage     Længde:\n");
    for(int i = 1; i <= *numberOfShips; i++){
        printf("%d:     %-16s%-18d%-7d\n", i, shipArray[i-1].name, shipArray[i-1].amountLeft, shipArray[i-1].length);   
    }
    
    int stopScanning = false;
    

    //get ship from user
    while(!stopScanning){
        printf("\nIndtast skib at placere (1-4): ");
        if (scanf("%d", shipChosen) != 1 || *shipChosen < 1 || *shipChosen > 4) {
            printf("Ugyldigt valg! Vælg et skib mellem 1 og 4.\n");
            while (getchar() != '\n');
            continue; 
        }
        *shipChosen -= 1;
        stopScanning = true;
    }
    

    //get orientation from user
    while(!stopScanning){
        printf("Vælg orientering (v=vandret, l=lodret): ");
        while (getchar() != '\n');
        if (scanf("%c", orientation) != 1 || (*orientation != 'v' && *orientation != 'l')) {
            printf("Ugyldigt valg! Vælg 'v' for vandret eller 'l' for lodret.\n");
            continue;
        }
        stopScanning = true;
    }
    if(*orientation == 'v') printf("Vandret %s valgt.", shipArray[*shipChosen].name);
    if(*orientation == 'l') printf("Lodret %s valgt.", shipArray[*shipChosen].name);
    

    //get coords from user
    int ycoord = 0;
    char xcoord = 0;

    printf("\nVælg koordinat for placering af skib (eg. A4. L går op fra koordinat, V til højre): ");

    while(!stopScanning){
        char buffer[3] = {0};
        
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

        if (sscanf(buffer, "%c%d", &xcoord, &ycoord) != 2) {
            printf("Invalid input! Try again: ");
            continue;
        } 
        
        stopScanning = true;
    }

    printf("%c, %d", xcoord, ycoord);

}
