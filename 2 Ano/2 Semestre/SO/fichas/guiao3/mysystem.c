#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int mysystem(const char *command){
    char *command_copy = strdup(command);
    char *input[100];
    char *token;
    int i = 0;
    while ((token = strsep(&command_copy, " ")) != NULL)
        input[i++] = strdup(token);
    input[i] = NULL;
    pid_t pid = fork();
    if (pid == 0){
        execvp(input[0], input);
        perror("execvp failed");
        _exit(1);
    } else {
        int status;
        wait(&status);
        free(command_copy);
        if (WIFEXITED(status))
            return WEXITSTATUS(status);
        else
            return -1;
    }
}