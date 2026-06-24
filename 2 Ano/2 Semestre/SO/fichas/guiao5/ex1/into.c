#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

int main(){
    int fifo_fd = open("fifo", O_WRONLY);
    if (fifo_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    ssize_t bytesRead = 0;
    while((bytesRead = read(0, buffer, 100)) > 0) {
        write(fifo_fd, buffer, bytesRead);
    }
}