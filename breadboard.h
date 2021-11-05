#include <stdbool.h>
//declaration of all breadboard functions
int addResistor(int row, int row2, char** breadboard, int rows, int columns, char count);
int removeResistor(char** breadboard, int rows, int columns, char count);
void printBreadboard(char** breadboard, int rows, int columns);
int findConnection(int rows, char** breadboard, int start, int end, bool* visited);
int checkIfOccupied(char** breadboard, int rows, int columns, int row, int row2, int start, int end);
