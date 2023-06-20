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

    int fd1 = open("myFIFO1", O_WRONLY);
    int fd2 = open("myFIFO2", O_RDONLY);

    while (1)
    {
        printf("Enter message you want to send: \n");
        scanf("%s", str1);
        write(fd1, str1, strlen(str1) + 1);
        sleep(1);
        read(fd2, str2, sizeof(str2));
        printf("Received message: %s \n", str2);
    }
    return 0;
}
