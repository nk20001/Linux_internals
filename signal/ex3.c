#include<stdio.h>
#include <signal.h>
#include<unistd.h>

void error(int sig)
{
        printf("ohhh! - i stopped  %d\n",sig);
        //(void) signal (SIGINT, SIG_DFL);
	printf("wake up time is 2secs");
	alarm(2);
}
int main()
{
        //printf("my process id is %d",getpid());
        (void) signal(SIGINT, error);
	signal (SIGALRM, SIG_IGN);
        //while(1)
        //{
               // signal (SIGALRM , error);
               // printf("hello World\n");
       // }
	alarm(2);
	while(1);
	return 0;
}

