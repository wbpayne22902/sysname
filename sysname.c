/*
   Welcome to my app.
   This app is a simple console app that tells you what Unix-based system
   you are running.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <libgen.h>
#include <unistd.h>

int main(int ac, char *av[]) {
	struct utsname a;
	uname(&a);
	pid_t p = getpid();
	pid_t pp = getppid();
	printf("%s[%d:%d]: You are running %s ver %s on a(n) %s.\n", basename(av[0]), p, pp, a.sysname, a.release, a.machine);
	for (int i = 1; i <= 15; i++) {
		printf("i[%d] = %d.\t", i, i);
	}
	
	printf("\n");
	
	printf("Now exiting...\n");
	return EXIT_SUCCESS;
}

