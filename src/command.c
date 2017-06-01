#include <unistd.h>
#include <stdio.h>
#include "command.h"

int command(char **args) {
    return execvp(args[0], args);
}
