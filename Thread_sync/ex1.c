#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int global = 0;

void* thread_function1();
void* thread_function2();

int main()
{
    int ret_val1;
    int ret_val2;
    pthread_t threadID1;
    pthread_t threadID2;

    ret_val1 = pthread_create(&threadID1, NULL, thread_function1, NULL);
    if(ret_val1 != 0)
    {
        perror("Thread");
        exit(1);
    }

    ret_val2 = pthread_create(&threadID2, NULL, thread_function2, NULL);
    if(ret_val2 != 0)
    {
        perror("Thread");
        exit(2);
    }

    sleep(5);
    printf("Main thread exit! \n");
    pthread_exit(NULL);
}

void* thread_function1()
{
    int local;
    printf("Thread function1 started! \n");

    for(int i = 0; i < 100; i++)
    {
        //sleep(1);
        global++;
        local = global;
        global = local;
        printf("Global value: %d \n", global);
    }
}

void* thread_function2()
{
    int local;
    printf("Thread function2 started! \n");

    for(int i = 0; i < 100; i++)
    {
        //sleep(1);
        global++;
        local = global;
        global = local;
        printf("Global value: %d \n", global);
    }
}
