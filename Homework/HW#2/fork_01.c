#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	int pid;
	int status;
	pid = fork(); /* 새로운 프로세스 복제 */
	if (pid < 0) { /* 오류 발생*/
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { /* 자식 프로세스 */
		printf("Child: %d Parent: %d\n", getpid(), getppid());
		exit(3);
	}
	else { /* 부모 프로세스 */
		wait(&status);
		printf("Parent: %d Child: %d\n", getpid(), pid);
		printf("Status : %d\n", status >> 8);
	}
	return 0;
}