#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int flag = 0;
char buffer[100];

void* fun1();
void* fun2();

int main()
{
    pthread_t threadID1;
    pthread_t threadID2;

    pthread_create(&threadID1, NULL, fun1, NULL);
    pthread_create(&threadID2, NULL, fun2, NULL);

    pthread_join(threadID1, NULL);
    pthread_join(threadID2, NULL);
    
    printf("Main thread Exit \n");
}

void* fun1()
{
    printf("Function-1 scheduled \n");
    sleep(0.5);

    pthread_mutex_lock(&mtx);
    sprintf(buffer, "Anything goes here!!");
    flag = 1;

    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mtx);
}

void* fun2()
{
    printf("Function-2 scheduled \n");
    pthread_mutex_lock(&mtx);

    if(flag == 0)
    {
        pthread_cond_wait(&cond, &mtx);
    }
    printf("Signal received from Function-1, Flag: %d \n", flag);
    printf("Data received from buffer: %s \n", buffer);

    pthread_mutex_unlock(&mtx);
    return(EXIT_SUCCESS);
}
