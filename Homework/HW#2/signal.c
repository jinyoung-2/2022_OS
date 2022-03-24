#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void signal_handler(int signum)
{
	printf("Caught signal %d\n", signum);
	exit(signum);
}
int main()
{
	signal(SIGINT, signal_handler); // 시그널 SIGINT의 처리함수 등록
	while (1) {
		printf("Program processing here.\n");
		sleep(1);
	}
	return 0;
}