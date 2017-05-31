#include <unistd.h>
#include <stdio.h>
#include "command.h"

int command(char **args) {
    pid_t pid;
    pid = fork();
    if ( pid == 0 ) {
        if ( execvp(args[0], args) == -1 ) {
            perror("psh");
        }
    } else if ( pid < 0 ) {
        perror("psh");
        return 0;
    }
    return 1;
}
