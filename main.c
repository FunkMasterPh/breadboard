#include <stdio.h>
#include <stdlib.h>
#include "breadboard.h"

int main(void){
    char count = '1';
    char resistorNumber;
    int rows;
    int columns;
    int row;
    int column;
    int row2;
    int column2;
    int menuChoice;
    while(1){
        printf("How many rows do you want: \n");
        if(scanf("%d", &rows) != 1){
            printf("Invalid input.\n");
            getc(stdin);
            continue;
        }
        printf("How many columns do you want: \n");
        if(scanf("%d", &columns) != 1){
            printf("Invalid input.\n");
            getc(stdin);
            continue;
        }
    break;
    }
    char** breadboard = malloc(rows * sizeof(char*));
    for(int i = 0; i < rows; i++){
        breadboard[i] = malloc(columns * sizeof(char));
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            breadboard[i][j] = '0';
        }
    }
    while(1){
        printf("Choose: \n");
        printf("1. Add resistor.\n");
        printf("2. Print current breadboard.\n");
        printf("3. Remove existing resistor.\n");
        printf("4. Exit program.\n");
        scanf("%d", &menuChoice);
        switch(menuChoice){
            case 1:
                addResistor(row, row2, column, column2, breadboard, rows, columns, count);
                count++;
                break;
            case 2:
                printBreadboard(breadboard, rows, columns);
                break;
            case 3:
                removeResistor(breadboard, resistorNumber, rows, columns, count);
                count--;
                break;
            case 4:
                free(breadboard);
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                getc(stdin);
                break;
        }
    }    
    return 0;
}