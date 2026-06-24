#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

#define BUFFER 1024

int main (int argc, char *argv[]){
    if (argc != 2)
        return 1;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        perror("opening");
    char *buffer = malloc(sizeof(char) * BUFFER);
    ssize_t r;
    int lines = 0, words = 0, bytes = 0;
    while ((r = read(fd, buffer, BUFFER)) > 0){
        bytes += r;
        for (int i = 0; i < r; i++){
            int tmp = 0;
            while (i < r && (!isspace(buffer[i]) && isprint(buffer[i]))){
                i++;
                tmp = 1;
            }
            if (tmp)
                words++;
            if (buffer[i] == '\n')
                lines++;
        }
    }
    printf("%d %d %d\n", lines, words, bytes);
    close(fd);
    free(buffer);
    return 0;
}