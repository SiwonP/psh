#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int main(void) {
	char* cwd;
	char buff[PATH_MAX+1];
	cwd = getcwd(buff, PATH_MAX+1);
	if (cwd != NULL) {
		printf("%s",cwd);
		printf("\n");
	}
	return EXIT_SUCCESS;
}
