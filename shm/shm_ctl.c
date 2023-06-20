#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define KEY 1234
struct shmid_ds buf;

int main()
{
        int shmid;
        void * mem;
        int shmc;
        shmid= shmget(KEY,8000,IPC_CREAT|0666);
if(shmid>=0)
{
printf("Shared Memory Created Sucessfully");
}
         shmc= shmctl( shmid,IPC_STAT, &buf);
        printf("Queue :%d\n ",buf.shm_segsz);
        printf("Queue :%d\n ",buf.shm_atime);
}
