#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER 1024

int main(int argc, char *argv[]){
    if (argc > 2)
        return 1;
    int fd = open(argv[1], O_RDONLY);
    char *buffer = malloc(sizeof(char) * BUFFER);
    ssize_t r;

    if (argc == 1)
        fd = STDIN_FILENO;
    else{
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
            perror("opening");
    }

    while ((r = read(fd, buffer, BUFFER)) > 0){
        write(STDOUT_FILENO, buffer, r);
        r = read(fd, buffer, BUFFER);
    }
    if (fd != STDIN_FILENO)
        close(fd);
    free(buffer);
    return 0;
}