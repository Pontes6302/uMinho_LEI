#include "matrix.h"


int **createMatrix() {

    // seed random numbers
    srand(123456); // fixed seed
    //srand(time(NULL)); // seed based on time - always changing

    // Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d...", MAX_RAND);
    int **matrix = (int **) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand() % MAX_RAND;
        }
    }
    printf("Done.\n");

    return matrix;
}

void printMatrix(int **matrix) {

    for (int i = 0; i < ROWS; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%7d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int lineCount(int *line, int value){
    int count = 0;
    for (int i = 0; i < COLUMNS; i++) {
        if (line[i] == value)
            count++;
    }
    return count;
}

void lookupNumber(int** matrix, int value, int* vector){
    pid_t pids[ROWS];
    int fildes[2];

    for (int i = 0; i < ROWS; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            Minfo res;
            res.line_nr = i;
            res.ocur_nr = lineCount(matrix[i], value);
            write(fildes[1], &res, sizeof(res));
            close(fildes[1]);
            _exit(0);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        wait(NULL);
    }

    for (int i = 0; i < ROWS; i++) {
        Minfo res;
        read(fildes[0], &res, sizeof(res));
        vector[res.line_nr] = res.ocur_nr;
    }

}