/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
        char ch[20];
        char ch1[20];
        mkfifo("f1",0666);
        mkfifo("f2",0666);
        int fd=open("f1",O_WRONLY);
        int fd1=open("f2",O_RDONLY);
        while(1)
	{
		read(fd,ch1,sizeof(ch1));
		printf("recieved messages :%s\n",ch1);
		sleep(1);
		printf("enter the message to send ...\n");
		scanf("%s",ch);
		write(fd1,ch,strlen(ch)+1);
        }
}*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    char str1[20];
    char str2[20];

    mkfifo("myFIFO1", 0666);
    mkfifo("myFIFO2", 0666);

    int fd1 = open("myFIFO1", O_RDONLY);
    int fd2 = open("myFIFO2", O_WRONLY);

    while (1)
    {
        read(fd1, str1, sizeof(str1));
        printf("Received message: %s \n", str1);
        printf("Enter message you want to send: \n");
        scanf("%s", str2);
        write(fd2, str2, strlen(str2) + 1);
        sleep(1);
    }
    return 0;
}

