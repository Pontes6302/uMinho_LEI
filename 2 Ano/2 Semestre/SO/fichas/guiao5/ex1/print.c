#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>

int main(){
    int fifo_fd = open("fifo", O_RDONLY);
    if (fifo_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    ssize_t bytesRead = read(fifo_fd, buffer, sizeof(buffer) - 1);
    while(bytesRead > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the string
        bytesRead = read(fifo_fd, buffer, sizeof(buffer) - 1);
    }
}