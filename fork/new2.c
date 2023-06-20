#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>
static void sig_handler (int signo)
{
	if (signo == SIGUSR1)
		printf("Parent caught sigusr1:\n");
}

int main()
{
	pid_t cpid;
	int status =0;
	int num = 5;
	cpid = fork();
	if (cpid == -1)
		exit(-1);

	if (cpid == 0)
	{
		printf("child process : before exec\n");
		exec1("./new2","arg1","arg2",NULL);
		printf("\nChild process : line is not printed\n");
	}
	else
	{
		if(signal (SIGUSR1, sig_handler) == SIG_ERR)
		{
			fprintf(stderr, "Cannot handle SIGUSR1 !\n");
			exit(1);
		}
	printf("\n Parent executing before process %d\n"cpid);
	sleep

}
