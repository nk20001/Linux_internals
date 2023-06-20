#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

int global=0;

static void *threadfunc1(void *arg){
 int count,local;
 local =1000;
 printf("Thread Function 1 started\n");
 for(count=0;count<100;count++){
         local=global;
         local++;
         global=local;
}
printf("the value of local variable is %d\n",local);

         //sleep(2);
}


static void *threadfunc2(void *arg){
 int count, local;
 local =100000;
 printf("Thread Function 2 started\n");
 for(count=0;count<100;count++){
         local=global;
         local++;
         global=local;
 }
 printf("the value of local variable is %d\n",local);

         //sleep(2);

}


int main(){
        int a1,a2;
        pthread_t id1,id2;
        a1=pthread_create(&id1,NULL,threadfunc1,"Hello");
        a2=pthread_create(&id2,NULL,threadfunc2,"World");
        //sleep(5);
        printf("The value of global variable is %d\n",global);
	//printf("the value of local variable is %d\n",local);

        }
