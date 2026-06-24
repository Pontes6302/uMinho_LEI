#include <stdio.h>
#include "mysystem.h"

void controller(int N, char** commands) {
    pid_t pids[N];
    for (int i = 0; i < N; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
			int status = 1;
			int nr = 0;
			while (status != 0){
				status = mysystem(commands[i]);
				nr++;
			}
            _exit(nr);
        }
    }

    for (int i = 0; i < N; i++) {
		int count;
        waitpid(pids[i], &count, 0);
        printf("%s %d\n", commands[i], WEXITSTATUS(count));
    }
}

int main(int argc, char* argv[]) {

    char *commands[argc-1];
    int N = 0;
	for(int i=1; i < argc; i++){
		commands[N] = strdup(argv[i]);
		printf("command[%d] = %s\n", N, commands[N]);
        N++;
	}

    controller(N, commands);

	return 0;
}