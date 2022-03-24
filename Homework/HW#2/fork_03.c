#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
char* read_command() {
	return "/bin/ls";
}
int main() {
	while (1) {
		char* cmd = read_command();
		int pid;
		if ((pid = fork()) == 0) { /* child process */
			execlp(cmd, "ls", NULL);
		}
		else { /* parent process */
		/* parent will wait for the child to complete */
			wait(pid);
		}
	}
}