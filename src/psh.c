#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "parse.h"
#include "command.h"

int main(void) {
	char* cwd=NULL;
	char buff[PATH_MAX+1];
	cwd = getcwd(buff, PATH_MAX+1);
	if (cwd != NULL) {
		printf("%s",cwd);
		printf("\n");
	}
	
    char *cmdLine;
    char **tokens;

    do{
    cmdLine = read_line();
    tokens = split_line(cmdLine);
    
    command(tokens);

    free(tokens);
    } while (1);
    return EXIT_SUCCESS;
}
