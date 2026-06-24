#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "defs.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Missing argument.\n");
        _exit(1);
    }

    int pid = getpid();
    char fifo_resp[64];
    snprintf(fifo_resp, sizeof(fifo_resp), "%s_%d", CLIENT, pid);
    if (mkfifo(fifo_resp, 0666) < 0) {
        perror("mkfifo client");
        exit(1);
    }

    Msg msg;
    msg.needle = atoi(argv[1]);
    msg.pid = pid;
    msg.occurrences = 0;

    int fd_server = open(SERVER, O_WRONLY);
    if (fd_server < 0) {
        perror("open SERVER");
        unlink(fifo_resp);
        exit(1);
    }
    if (write(fd_server, &msg, sizeof(Msg)) != sizeof(Msg)) {
        perror("write SERVER");
        close(fd_server);
        unlink(fifo_resp);
        exit(1);
    }
    close(fd_server);

    int fd_resp = open(fifo_resp, O_RDONLY);
    if (fd_resp < 0) {
        perror("open client FIFO");
        unlink(fifo_resp);
        exit(1);
    }
    if (read(fd_resp, &msg, sizeof(Msg)) == sizeof(Msg)) {
        printf("Ocorrências de %d: %d\n", msg.needle, msg.occurrences);
    } else {
        perror("read client FIFO");
    }
    close(fd_resp);
    unlink(fifo_resp);
    return 0;
}