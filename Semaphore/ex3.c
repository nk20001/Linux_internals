#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	int sval;
	unsigned int value;
	sem_t *sem;
	sem = sem_open("/seme1",O_CREAT | O_RDWR, 0660, 1);
	if (sem == SEM_FAILED)
	{
		perror ("sem_open fail");
		return -1;
	}
	else
	{
		printf("\n sem sucessfully opened");
	}

	sem_getvalue(sem, &sval);
	printf("\n before sem_wait semaphorevalue %d\n",sval);

	sem_wait(sem); 
	sem_getvalue(sem, &sval);
	printf("\n after sem_wait semaphorevalue %d\n",sval);

	printf("\n process 1:executing critical section");
	sleep(5);
	sem_post(sem);
	printf("critiv=cal section executed");
	sem_getvalue(sem, &sval);
	printf("\n after sem_post semaphore value %d\n",sval);
	sem_unlink("/seme1");
}

