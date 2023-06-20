#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static int global = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;


static void* thread_function();

int main()
{
    int ret_val;
    pthread_t threadID1;

    ret_val = pthread_create(&threadID1, NULL,thread_function,NULL);
    if(ret_val != 0)
    {
        perror("Thread create");
        exit(1);
    }
    ret_val = pthread_join(threadID1, NULL);
    if(ret_val != 0)
    {
        perror("Thread join");
        exit(3);
    }
    printf("Global Value: %d \n", global);
    printf("Main thread exit! \n");
    pthread_exit(NULL);
}

void* thread_function()
{
    int local;
    printf("Thread function1 started! \n");
    pthread_mutex_lock(&mut);

    for(int i = 0; i < 100; i++)
    {
        local = global;
        local++;
        global = local;

    }
    pthread_mutex_unlock(&mut);

    printf("Thread1:%d\n",local);
    return NULL;
}

