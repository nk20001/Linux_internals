#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<stdio.h>

#define KEY 1234

int main()
{
	int semid;
	semid= semget(KEY, 1, IPC_CREAT | 0666);
	if(semid ==0)
	{
		printf("file created");
	}
	else
	{
		printf("file not created");
	}
}

