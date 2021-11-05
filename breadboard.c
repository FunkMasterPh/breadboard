#ifndef BREADBOARD_H
#define BREADBOARD_H
#include "breadboard.h"
#include <stdlib.h>
#include <stdio.h>

int addResistor(int row, int row2, char** breadboard, int rows, int columns, char count){
    int column, column2;
    //takes user input and places resistor if data inputted correctly
    while(1){
        printf("Add row and column number where you want to place the first leg of resistor: \n");
        if(scanf("%d %d", &row, &column) != 2){
            printf("Invalid input.\n");
            while ((getchar()) != '\n');
            continue;
        }
        printf("Add row and column number where you want to place the second leg of resistor: \n");
        if(scanf("%d %d", &row2, &column2) != 2){
            printf("Invalid input.\n");
            while ((getchar()) != '\n');
            continue;
        }
        //error handling
        if(row <= 0 || row2 <= 0 || row > rows || row2 > rows || column <= 0 || column2 <= 0 || column > columns || column2 > columns){
            printf("Invalid placement.\n");
            while ((getchar()) != '\n');
            continue;
        }
        if(row != row2){
            printf("Resistors can only be placed horizontaly.\n");
            while ((getchar()) != '\n');
            continue;
        }else if(column == column2){
            printf("Can't place two resistor legs in same slot.\n");
            while ((getchar()) != '\n');
            continue;
        }else if(breadboard[row-1][column-1] > '0' || breadboard[row-1][column-1] == '-'){
            printf("Slot already occupied.\n");
            while ((getchar()) != '\n');
            continue;
        }
        else{
            //placing of resistor and '-' between resistor legs
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
            printf("Resistor added.\n");
            while ((getchar()) != '\n');
            break;
        }    
    }
    return 0;
}

int findConnection(int rows, char** breadboard, int start, int end, bool* visited){
    //checks if current column is end point in connection
    if(visited[end]){
        return 1;
    }
    //takes user input and loops trough the breadboard to find connection
    for(int i = 0; i < rows; i++){
        if(breadboard[i][start] > '0'){
            //checks if connection goes to the right by checking next index for '-',
            //if true marks current column visited and calls funtion again
            if(breadboard[i][start+1] == '-'){
                start++;
                while(breadboard[i][start] == '-'){
                    start++;
                }
                int x = start;
                if(visited[x] != true){
                    visited[x] = true;
                    if(findConnection(rows, breadboard, x, end, visited)){
                        return 1;
                    }
                }else{
                    continue;
                }
            //checks if connection goes to the left by checking previous index for '-', 
            //if true marks current column visited and calls funtion again
            }else if(breadboard[i][start-1] == '-'){
                start--;
                while(breadboard[i][start] == '-'){
                    start--;
                }
                int x = start;
                if(visited[x] != true){
                    visited[x] = true;
                    if(findConnection(rows, breadboard, x, end, visited)){
                        return 1;
                    }
                }else{
                    continue;
                }
            }   
        }
    }
    return 0;
}

int removeResistor(char** breadboard, int rows, int columns, char count){
    char resistorNumber;
    //clears input buffer
    while ((getchar()) != '\n');
    while(1){
        //takes the number of the resistor to remove and checks for user error
        printf("Enter number of the resistor you want to remove: \n");
        if(scanf("%c", &resistorNumber) != 1 || resistorNumber >= count || resistorNumber <= '0'){
            printf("Invalid input.\n");
            continue;
        }
    break; 
    }
    //finds the right resistor and removes it
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
    //lowers the resistor number of the rest of the resistors to keep count consistant
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(breadboard[i][j] > resistorNumber){
                breadboard[i][j]--;
            } 
        }
    }
    printf("Resistor removed.\n");
    while ((getchar()) != '\n');
    return 0;
}

void printBreadboard(char** breadboard, int rows, int columns){
    //prints the breadboard with formatting
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
    getc(stdin);
}

int checkIfOccupied(char** breadboard, int rows, int columns, int row, int row2, int start, int end){
    //loops trough the whole breadboard and checks if inputted slot is occupied
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(breadboard[row-1][start-1] > '0' && breadboard[row2-1][end-1] > '0'){
                return 1;
            }
        }
    }
    return 0;
}



#endif
