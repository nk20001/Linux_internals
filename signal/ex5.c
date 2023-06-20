#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void Signal_Handler(int sig);

int main()
{
    pid_t fork_ID;
    fork_ID = fork();

    if(fork_ID == 0)
    {
        printf("Child Process! PID: %d \n", getpid());
    }
    else
    {
        printf("Parent process! PID: %d \n", getpid());
        (void) signal(SIGCHLD, Signal_Handler);
        while(1)
        {
            printf("I am from MARS! \n");
            sleep(1);
        }
    }
    return 0;
}

void Signal_Handler(int sig)
{
    printf("Nothing special, Just a signal Handler! \n");
    wait(NULL);
}

