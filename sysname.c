/*
   Welcome to my app.
*/
#include <stdio.h>
#include <sys/utsname.h>
#include <libgen.h>
#include <unistd.h>

int main(int ac, char *av[]) {
	struct utsname a;
	uname(&a);
	pid_t p = getpid();
	printf("%s[%d]: You are running %s ver %s on a(n) %s.\n", basename(av[0]), p, a.sysname, a.release, a.machine);
	printf("Now exiting...\n");
	return 0;
}

