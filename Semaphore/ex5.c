#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include<stdio.h>
#include<sys/ipc.h>
int main()
{
        int sval;
        sem_t *sem;
        sem=sem_open("ram",O_CREAT | O_RDWR, 0660, 2);
        if(sem==0)
        {
                printf("SEM_open fail\n");
        }
        else
        {
                printf("SEm opened sucessfully\n");
        }
        sem_getvalue(sem,&sval);
        printf("Value of sval%d\n",sval);
        sem_wait(sem);
        sem_getvalue(sem,&sval);
        printf("Value of sval%d\n",sval);
        printf("Executing Critical Section\n");
        sleep(20);
        sem_post(sem);
        printf("Critical Section Executed");
        sem_getvalue(sem,&sval);
        printf("Value of sval%d\n",sval);


}
