#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "parse.h"

int main(void) {
	char* cwd=NULL;
	char buff[PATH_MAX+1];
	cwd = getcwd(buff, PATH_MAX+1);
	if (cwd != NULL) {
		printf("%s",cwd);
		printf("\n");
	}
	
    char cmdLine[PATH_MAX];
    fgets(cmdLine, sizeof(cmdLine), stdin);
    printf("%s", cmdLine);
    
    char *arguments[] = { "ls", NULL };
    
    if (execv("/bin/ls",arguments)==-1){
        return EXIT_FAILURE;
    };
	return EXIT_SUCCESS;
}
