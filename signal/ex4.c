
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void num (int sig)
{
printf("Hello:%d\n",sig);
//(void) signal (SIGINT,SIG_DFL);
}
void sign (int abc)
{
printf("Hi:%d\n",abc);
}
int main()
{
printf("ID:%d\n",getpid());
signal(SIGHUP,num);
signal(SIGSTOP,sign);

while(1)
{
printf("hello world\n");
sleep(1);
}
return 0;
}
