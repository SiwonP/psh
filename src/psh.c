#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "parse.h"
#include "command.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(void) {
	char* cwd=NULL;
	char buff[PATH_MAX+1];
	
    char *cmdLine;
    char **tokens;

    do{
    cwd = getcwd(buff, PATH_MAX+1);
    if (cwd != NULL) {
        printf(ANSI_COLOR_RED "%s >> " ANSI_COLOR_RESET, cwd);
    }
    cmdLine = read_line();
    tokens = split_line(cmdLine);
    
    command(tokens);

    free(tokens);
    } while (1);
    return EXIT_SUCCESS;
}
