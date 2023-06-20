#include<unistd.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myConVar = PTHREAD_COND_INITIALIZER;

int doneFlag =0;
char buf[100];

//producer thread
 
void * threadA(void *p)
{
	printf("\nthreadA :critical execution first");

	sprintf(buf,"this is data buffer");
	doneFlag =1;
	pthread_cond_signal (&myConVar);
	pthread_mutex_unlock(&my_mutex);
}

#if 1
void  * threadB (void *p)
{
	printf("\nthreadB Scheduled first \n");
	pthread_mutex_lock(&my_mutex);
	if (doneFlag == 0)
		pthread_cond_wait(&myConVar, &my_mutex);
	printf("threadB %d\n",doneFlag);
	printf("the buffer recieved (%s)\n",buf);
	pthread_mutex_unlock(&my_mutex);
}

int main(int argc , char** argv)
{
	srand(time(0));
	pthread_t pthreadA;
	pthread_create(&pthreadA, NULL, threadA, NULL);




