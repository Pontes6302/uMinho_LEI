#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"
#include "vector.h"

//FIFO criado pelo servidor
//Cliente pode receber um sigpipe (concorrência!)

int main (int argc, char * argv[]){

	init_vector();
	print_vector();

    mkfifo(SERVER, 0666);

    // Abre para leitura e escrita para evitar EOF quando não há clientes
    int fd_server = open(SERVER, O_RDWR);
    if (fd_server < 0) {
        perror("open SERVER");
        exit(1);
    }

    Msg msg;
    while (1) {
        ssize_t n = read(fd_server, &msg, sizeof(Msg));
        if (n == sizeof(Msg)) {
            msg.occurrences = count_needle(msg.needle);

            char fifo_resp[64];
            snprintf(fifo_resp, sizeof(fifo_resp), "%s_%d", CLIENT, msg.pid);
            int fd_client = open(fifo_resp, O_WRONLY);
            if (fd_client >= 0) {
                write(fd_client, &msg, sizeof(Msg));
                close(fd_client);
            }
        }
    }

    // Nunca chega aqui, mas por completude:
    close(fd_server);
    unlink(SERVER);
    return 0;
    return 0;
}