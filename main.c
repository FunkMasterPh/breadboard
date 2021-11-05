#include <stdio.h>
#include <stdlib.h>
#include "breadboard.h"
#include <stdbool.h>

int main(void){

    int start, end, rows, columns, row, row2, menuChoice;
    char count = '1';
    
    while(1){
        //taking user input to determine size of breadboard
        printf("How many rows do you want: \n");
        if(scanf("%d", &rows) != 1){
            printf("Invalid input.\n");
            while ((getchar()) != '\n');
            continue;
        }
        printf("How many columns do you want: \n");
        if(scanf("%d", &columns) != 1){
            printf("Invalid input.\n");
            while ((getchar()) != '\n');
            continue;
        }
    break;
    }
    //allocates memory for bredboard and visited array
    char** breadboard = malloc(rows * sizeof(char*));
    for(int i = 0; i < rows; i++){
        breadboard[i] = malloc(columns * sizeof(char));
    }
    bool* visited = malloc(rows * sizeof(bool));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            breadboard[i][j] = '0';
        }
    }
    while(1){
        //main menu
        printf("Choose: \n");
        printf("1. Add resistor.\n");
        printf("2. Print current breadboard.\n");
        printf("3. Remove existing resistor.\n");
        printf("4. See if two points are connected.\n");
        printf("5. Exit program.\n");
        scanf("%d", &menuChoice);
        switch(menuChoice){
            case 1:
                addResistor(row, row2, breadboard, rows, columns, count);
                count++;
                break;
            case 2:
                printBreadboard(breadboard, rows, columns);
                break;
            case 3:
                removeResistor(breadboard, rows, columns, count);
                count--;
                break;
            case  4:
                //takes user input to determine the two points to find connection
                while(1){
                    printf("Enter first point: \n");
                    if(scanf("%d %d", &row, &start) != 2){
                        printf("Invalid input.\n");
                        while ((getchar()) != '\n');
                        continue;
                    }
                    printf("Enter second point: \n");
                    if(scanf("%d %d", &row2, &end) != 2){
                        printf("Invalid input.\n");
                        while ((getchar()) != '\n');
                        continue;
                    }
                    break;
                }
                //takes user input and checks if the slots are occupied, if true calls findConnection function
                if(checkIfOccupied(breadboard, rows, columns, row, row2, start, end) == 1){
                    start = start - 1;
                    end = end - 1;
                    for(int i = 0; i < rows; i++){
                        visited[i] = false;
                    }
                    visited[start] = true;
                    if(findConnection(rows, breadboard, start, end, visited)){
                        printf("They are connected.\n");
                        free(visited);
                    }else{
                        printf("They are not connected.\n");
                    }
                }else{
                    printf("No resistor in that slot.\n");
                }
                break;
            case 5:
                for(int i  = 0; i < rows; i++){
                    free(breadboard[i]);
                }
                free(breadboard);
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                while ((getchar()) != '\n');
                break;
        }
    }    
    return 0;
}