/*
   Welcome to my app.
   This app is a simple console app that tells you what Unix-based system
   you are running. Cool
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <libgen.h>
#include <unistd.h>
#include <fcntl.h>

#define mainname "sysout.txt"
int main(int ac, char *av[]) {
	struct utsname a;
	uname(&a);
	pid_t p = getpid();
	pid_t pp = getppid();
	printf("%s[%d:%d]: You are running %s ver %s on a(n) %s.\n", basename(av[0]), p, pp, a.sysname, a.release, a.machine);
	for (int i = 1; i <= 15; i++) {
		printf("i[%d] = %d.\t", i, i);
	}
	int fd = open(mainname, O_CREAT | O_WRONLY | O_APPEND, 0644);
	dprintf(fd, "%s[%d:%d]: You are running %s ver %s on a(n) %s.\n", basename(av[0]), p, pp, a.sysname, a.release, a.machine);
	close(fd);
	printf("\n");
	printf("Thank you for using %s.\n", basename(av[0]));
	printf("Now exiting...\n");
	return EXIT_SUCCESS;
}

