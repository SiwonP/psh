#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parse.h"

#define BUFFSIZE 64

char *read_line(void) {
    char *cmdLine = NULL;
    size_t buffSize = 0;
    int n = 0;
    n = getline(&cmdLine, &buffSize, stdin);
    return cmdLine;
}

char **split_line(char *str) {
    char *ch = " \n";
    char *token = NULL;
    int buffSize = BUFFSIZE;
    char **tokens = malloc(buffSize * sizeof(char*));
    int position = 0;

    token = strtok(str, ch);

    while(token != NULL) {
        tokens[position] = token;
        printf("%s\n", tokens[position]);
        token = strtok(NULL, ch);
        position++;
    }
    tokens[position] = NULL;

    return tokens;
}
