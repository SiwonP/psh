#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "command.h"

int command(char **args) {
    pid_t pid;
    pid_t wait;
    int status;

    pid = fork();

    if ( pid == 0 ) {
        execvp(args[0], args);
    } else if ( pid > 0 ) {
        do {
            wait = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        return 0;
    }

    return 1;
}
