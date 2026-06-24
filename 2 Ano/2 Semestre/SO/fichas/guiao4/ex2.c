#include <unistd.h>
#include <stdio.h>


int main(){
    int fildes[2];
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        int i = 0;
        for (int j = 0; j < 1000; j++) {
            write (fildes[1], &i, sizeof(i));
            printf("child wrote: %d\n", i);
        }
        close(fildes[1]);
        _exit(0);
    } else {
        // Parent process
        close (fildes[1]);
        sleep(10);
        int read_i;
        while(read(fildes[0], &read_i, sizeof(read_i)))
            printf("parent read: %d\n", read_i);
        close(fildes[0]);
        printf("Received value: %d\n", read_i);
    }
}