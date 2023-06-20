#include<stdio.h>
#include <signal.h>
#include<unistd.h>

void error(int sig)
{
	printf("ohhh! - i stopped  %d\n",sig);
	//(void) signal (SIGINT, SIG_DFL);

}
int main()
{
	printf("my process id is %d",getpid());
	(void) signal(SIGINT, error);
	while(1)
	{
		signal (SIGTERM ,SIG_IGN );
		printf("hare krishna!\n");
		sleep(1);

	}
	return 0;
}


