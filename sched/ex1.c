#include<stdio.h>
#include<sched.h>

int main()
{
	int scheduler;
	scheduler = sched_getscheduler(getpid());

	printf("the schedular policy of current process%d\t is %d\n",getpid(), scheduler);
	printf("the max priority level of sched_other  %d\n", sched_get_priority_max(SCHED_OTHER));
	 printf("the min priority level sched_other  %d\n", sched_get_priority_min(SCHED_OTHER));
	 printf("the max priority level of sched_fifo  %d\n", sched_get_priority_max(SCHED_FIFO));
	 printf("the max priority level of sched_fifo  %d\n", sched_get_priority_max(SCHED_FIFO));
	 printf("the max priority level of sched_rr %d\n", sched_get_priority_max(SCHED_RR));
	 printf("the max priority level of sched_rr %d\n", sched_get_priority_max(SCHED_RR));
}





