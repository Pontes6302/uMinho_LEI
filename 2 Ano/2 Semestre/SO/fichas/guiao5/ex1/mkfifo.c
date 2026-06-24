#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    const char *fifo = "fifo";
    if (mkfifo(fifo, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    return 0;
}