#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	int pid;
	int status;
	pid = fork(); /* ���ο� ���μ��� ���� */
	if (pid < 0) { /* ���� �߻�*/
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { /* �ڽ� ���μ��� */
		printf("Child: %d Parent: %d\n", getpid(), getppid());
		exit(3);
	}
	else { /* �θ� ���μ��� */
		wait(&status);
		printf("Parent: %d Child: %d\n", getpid(), pid);
		printf("Status : %d\n", status >> 8);
	}
	return 0;
}