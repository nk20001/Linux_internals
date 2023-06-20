#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   int pid = fork();
   if (pid == 0)
   {
       printf(" I am child\n");
   }
   else if(pid > 0)
   {
       printf(" I am parent\n");
   }
   else
   {
       printf("My id:%d\n",getpid());
       printf("Error\n");
   }
   return 0;
}
