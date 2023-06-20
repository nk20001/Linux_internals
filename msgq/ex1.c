#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/ipc.h>

#define KEY 1234
int main()
{

	int msgid;
	msgid  =  msgget (KEY,IPC_CREAT);
	if(msgid >= 0)
	{
		printf("Mgq created succesfully %d \n ",msgid);
	}
}

	
