#include <sys/types.h>
#include <sys/stat.h>	
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GPIO_EN1 "/sys/class/gpio/export"
#define GPIO_DIR1 "/sys/class/gpio/PC13/direction"
#define GPIO_Val1 "/sys/class/gpio/PC13/value"

#define GPIO_EN2 "/sys/class/gpio/export"
#define GPIO_DIR2 "/sys/class/gpio/PC17/direction"
#define GPIO_Val2 "/sys/class/gpio/PC17/value"

#define GPIO_EN3 "/sys/class/gpio/export"
#define GPIO_DIR3 "/sys/class/gpio/PC19/direction"
#define GPIO_Val3 "/sys/class/gpio/PC19/value"


int main()
{
int gpio_fd1;
int gpio_fd2;
int gpio_fd3;

char gpio_buf1[30];
char gpio_buf2[30];
char gpio_buf3[30];

int gpio_num1=77;
int gpio_num2=81;
int gpio_num3=83;

int count=10;
gpio_fd1 = open(GPIO_EN1,O_WRONLY);
if(gpio_fd1 < 0)
{
printf("Unable to open  %s\n",GPIO_EN1);
exit(0);
}
sprintf(gpio_buf1,"%d",gpio_num1);
write(gpio_fd1,gpio_buf1,strlen(gpio_buf1));
close(gpio_fd1);



gpio_fd2 = open(GPIO_EN2,O_WRONLY);
if(gpio_fd2 < 0)
{
printf("Unable to open  %s\n",GPIO_EN2);
exit(0);
}
sprintf(gpio_buf2,"%d",gpio_num2);
write(gpio_fd2,gpio_buf2,strlen(gpio_buf2));
close(gpio_fd2);


gpio_fd3 = open(GPIO_EN3,O_WRONLY);
if(gpio_fd3 < 0)
{
printf("Unable to open  %s\n",GPIO_EN3);
exit(0);
}
sprintf(gpio_buf3,"%d",gpio_num3);
write(gpio_fd3,gpio_buf3,strlen(gpio_buf3));
close(gpio_fd3);


gpio_fd1=open(GPIO_DIR1,O_WRONLY);
if(gpio_fd1 < 0)
{
printf("Unable to open  %s",GPIO_DIR1);
exit(0);
}
write(gpio_fd1,"out",3);
close(gpio_fd1);

gpio_fd2=open(GPIO_DIR2,O_WRONLY);
if(gpio_fd2 < 0)
{
printf("Unable to open  %s",GPIO_DIR2);
exit(0);
}
write(gpio_fd2,"out",3);
close(gpio_fd2);


gpio_fd3=open(GPIO_DIR3,O_WRONLY);
if(gpio_fd3 < 0)
{
printf("Unable to open  %s",GPIO_DIR3);
exit(0);
}
write(gpio_fd3,"out",3);
close(gpio_fd3);


gpio_fd1 = open(GPIO_Val1,O_WRONLY);
if(gpio_fd1 < 0)
{
printf("Unable to open  %s",GPIO_Val1);
exit(0);
}

gpio_fd2 = open(GPIO_Val2,O_WRONLY);
if(gpio_fd2 < 0)
{
printf("Unable to open  %s",GPIO_Val2);
exit(0);
}

gpio_fd3 = open(GPIO_Val3,O_WRONLY);
if(gpio_fd3 < 0)
{
printf("Unable to open  %s",GPIO_Val3);
exit(0);
}

printf("Toggling GPIO_PIN\n");
while(count--)
{
write(gpio_fd1,"0",1);
sleep(2);
write(gpio_fd2,"1",1);
sleep(2);
write(gpio_fd3,"1",1);
sleep(2);



}


}


