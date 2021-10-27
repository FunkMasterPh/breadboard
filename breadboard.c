#ifndef BREADBOARD_H
#define BREADBOARD_H
#include "breadboard.h"
#include <stdlib.h>
#include <stdio.h>

int addResistor(int row, int column, int row2, int column2, char** breadboard){
    static char count = '1';
    while(1){
        printf("Add row and column number where you want to place the first leg of resistor: \n");
        scanf("%d %d", &row, &column);
        printf("Add row and column number where you want to place the second leg of resistor: \n");
        scanf("%d %d", &row2, &column2);
        if(row != row2){
            printf("Resistors can only be placed horizontaly.\n");
            continue;
        }else if(column == column2){
            printf("Can't place two resistor legs in same slot.\n");
            continue;
        }else if(breadboard[row-1][column-1] == '1' || breadboard[row-1][column-1] == '-'){
            printf("Slot already occupied.\n");
            continue;
        }
        else{
            breadboard[row-1][column-1] = count;
            breadboard[row2-1][column2-1]= count;
             if(column > column2){
                for(int i = column2 + 1; i < column; i++){
                    breadboard[row-1][i-1] = '-';
                }
            }
            for(int i = column + 1; i < column2; i++){
                breadboard[row-1][i-1] = '-';
            }
            count++;
            printf("Resistor added.\n");
            break;
        }    
    }
    return 0;
}

int removeResistor(char** breadboard, char resistorNumber, int rows, int columns){
    printf("Enter number of the resistor you want to remove: \n");
    getc(stdin);
    scanf("%c", &resistorNumber);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(breadboard[i][j] == resistorNumber){
                char* index1 = &breadboard[i][j];
                index1++;
                while(*index1 == '-'){
                    *index1 = '0';
                    index1++;
                }
            breadboard[i][j] = '0';
            }    
        }
    }
        return 0;
}


void printBreadboard(char** breadboard, int rows, int columns){
    printf("   ");
    for(int i = 0; i < columns; i++){
        if(i < 9){
            printf("%d  ", i+1);
        }else{
            printf("%d ", i+1);
        }
    }
    printf("\n");

    for(int i = 0; i < rows; i++){
        if(i < 9){
            printf("%d  ", i+1);
            for(int j = 0; j < columns; j++){
                printf("%c  ", breadboard[i][j]);
            }
            printf("\n");
        }else{
            printf("%d ", i+1);
            for(int j = 0; j < columns; j++){
                printf("%c  ", breadboard[i][j]);
            }
            printf("\n");
        } 
    }    
}


#endif
