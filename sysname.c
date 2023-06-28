/*
	Welcome to my app. v 2.1
	This app is a simple console app that tells you what Unix-based system
	you are running.
	It also writes the system name to a file and a notice that the file is being closed..
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <libgen.h>
#include <unistd.h>
#include <fcntl.h>
#define prodVer 0.8
#define mainname "sysout.txt"
int main(int ac, char *av[]) {
	// Declare main variables
	struct utsname a;
	int fd;
	uname(&a);
	//get process id and parent process id
	pid_t p = getpid();
	pid_t pp = getppid();
	printf("%s[%d:%d] (version %g): You are running %s ver %s on a(n) %s.\n", basename(av[0]), p, pp, prodVer, a.sysname, a.release, a.machine);
	for (int i = 1; i <= 15; i++) {
		printf("i[%d] = %d.\t", i, i);
	}
	printf("\n");
	//open file
	fd = open(mainname, O_CREAT | O_WRONLY | O_APPEND, 0644);
	dprintf(fd, "%s[%d:%d]: You are running %s ver %s on a(n) %s.\n", basename(av[0]), p, pp, a.sysname, a.release, a.machine);
	dprintf(fd, "Closing file with fd = %d....\n", fd);
	//close file
	close(fd);
	printf("Thank you for using %s.\n", basename(av[0]));
	printf("Now exiting...\n");
	return EXIT_SUCCESS;
}

