#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    if (pid == 0){
        printf("I am the child process, my PID is %d\n", getpid());
        execlp("ls", "ls", "-l", "-G", NULL);
        perror("execlp failed");
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else
            printf("Child process did not exit successfully\n");
    }
}