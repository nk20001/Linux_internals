#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include<stdio.h>
#include<unistd.h>


int main()
{
        int r, sval;
        sem_t *sem;
        sem = sem_open("/seme1", O_RDWR);

        if(sem == SEM_FAILED)
        {
                printf("sem_open fail\n");
                return -1;
        }
        else
        {
                printf("sem_open success\n");
        }

        sem_getvalue(sem, &sval);
        printf("semaphore value: %d\n", sval);

        r = sem_wait(sem);
        printf("Process 2 executing critical section\n");
        sleep(10);
        printf(" r is %d\n", r);
        printf("Process 2:\n");
        sem_post(sem);

        printf("Process 2 executed critical section\n");

	//sem_unlink("/seme1");
}
