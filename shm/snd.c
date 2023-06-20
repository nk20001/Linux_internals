#include <sys/types.h>
#include <sys/shm.h>
#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 1234

int main(){

   int i;
   void *mem;
   int buf;
   i=shmget(KEY,8000, IPC_CREAT);
   if(i >= 0)
   {
          printf("Shared memory segment created successfully\n");
   }
   printf("Address of the shared memory is : %d \n",i);

   mem = shmat(i,(const void *) 0,0);
   strcpy((char*)mem,"Hello world\n");

    i = shmctl(i,IPC_STAT,&buf);
    printf("Queue :%d\n ",buf.shm_dtime);
        printf("Queue :%d\n ",buf.shm_dtime);



  // printf("Number of attachment: %d",(int *)mem);


   return 0;

}
