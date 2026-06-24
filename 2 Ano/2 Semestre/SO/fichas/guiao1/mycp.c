#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define BUFFER 1024

int main (int argc, char *argv[]){
    if (argc != 3)
        return 1;
    clock_t start = clock();
    int fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1)
        perror("opening source");
    int fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd_dest == -1)
        perror("opening destination");
    char *buffer = malloc(sizeof(char) * BUFFER);
    ssize_t r;
    while ((r = read(fd_src, buffer, BUFFER)) > 0)
        write(fd_dest, buffer, r);
    close(fd_src);
    close(fd_dest);
    free(buffer);

    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("Time taken: %f ms\n", time);

    return 0;
}