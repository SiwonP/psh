#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "src/parse.h"
#include "src/command.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

int main(void) {
	char* cwd=NULL;
	char buff[PATH_MAX+1];
	
    char hostName[64];
    gethostname(hostName, sizeof(hostName));

    char *cmdLine;
    char **tokens;

    struct stat gitCheckBuf;
    const char *gitCheck = ".git";

    do{
    cwd = getcwd(buff, PATH_MAX+1);
    if (cwd != NULL) {
        if (stat(gitCheck, &gitCheckBuf) == 0) {
            printf(ANSI_COLOR_GREEN "%s:" ANSI_COLOR_RESET ANSI_COLOR_RED "%s  + git" ANSI_COLOR_RESET, hostName, cwd);
        } else {
            printf(ANSI_COLOR_GREEN "%s:" ANSI_COLOR_RESET ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, hostName, cwd);
        }
        printf("\n>>");
    }
    cmdLine = read_line();
    tokens = split_line(cmdLine);
    
    command(tokens);

    free(tokens);
    } while (1);
    return EXIT_SUCCESS;
}
