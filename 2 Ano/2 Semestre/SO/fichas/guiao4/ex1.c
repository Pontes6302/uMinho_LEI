#include <unistd.h>


int main(){
    int fildes[2];
    pid_t pid = fork();
    int i;

    if (pid == 0) {
        // Child process
        i = 12;
        write (fildes[1], &i, sizeof(i));
        close(fildes[1]);
        _exit(0);
    } else {
        // Parent process
        int i;
        read(fildes[0], &i, sizeof(i));
        close(fildes[0]);
        printf("Received value: %d\n", i);
    }
}