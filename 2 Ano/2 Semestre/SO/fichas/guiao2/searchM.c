#include "matrix.h"


int main(int argc, char *argv[]) {

    // generate random matrix
    int **matrix = createMatrix();

    // print matrix
//    printMatrix(matrix);

    // TO DO
    int value = 10;
    printf("Value to search: %d\n Found: %d\n", value, valueExists(matrix, value));

    linesWithValue(matrix, value);

    // free matrix
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}