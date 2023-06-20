#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	unsigned int value;
	sem_t *sem;
	sem = sem_open("/sema1",O_CREAT | O_RDWR, 0660, 1);
	if (sem == SEM_FAILED)
	{
		perror ("sem_open fail");
		return -1;
	}
	else
	{
		printf("\n sem sucessfully opened");
	}
}

