#include "matrix.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>


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

// ex.5
int valueExists(int **matrix, int value) {
    int found = 0;
    int finished = 0;
    pid_t pids[ROWS];

    for (int i = 0; i < ROWS; i++) {
        pids[i] = fork();
        if (pids[i] == 0) { // Filho
            for (int j = 0; j < COLUMNS; j++) {
                if (matrix[i][j] == value)
                    _exit(1);
            }
            _exit(0);
        }
    }

    while (finished < ROWS) {
        int wstatus;
        pid_t pid = wait(&wstatus);
        finished++;
        if (WEXITSTATUS(wstatus) == 1) {
            found = 1;
            for (int k = 0; k < ROWS; k++) {
                if (pids[k] != pid) {
                    kill(pids[k], SIGKILL);
                }
            }
            break;
        }
    }
    while (finished < ROWS) {
        wait(NULL);
        finished++;
    }
    return found;
}

void printline(int *line) {
    for (int j = 0; j < COLUMNS; j++) {
        printf("%d ", line[j]);
    }
    printf("\n");
}

// ex.6
void linesWithValue(int **matrix, int value) {
    pid_t pids[ROWS];

    for (int i = 0; i < ROWS; i++) {
        pids[i] = fork();
        if (pids[i] == 0) { // Filho
            for (int j = 0; j < COLUMNS; j++) {
                if (matrix[i][j] == value)
                    _exit(1);
            }
            _exit(0);
        }
    }

    int k = 0;
    while (k < ROWS) {
        int wstatus;
        waitpid(pids[k], &wstatus, 0);
        if (WEXITSTATUS(wstatus) == 1){
            printf("Line %d: \n\t", k);
            printline(matrix[k]);
        }
        k++;
    }
}