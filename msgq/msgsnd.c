/*#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define KEY 1234
typedef struct{
        long msgtype;
        char buffer[100];
}msg;

main()
{
	int qid;
        int i;
        qid = msgget(KEY, IPC_CREAT);
        printf("%d",qid);
        msgctl(qid,IPC_STAT,&buf);
        printf("Queue :%d\n ",buf.msg_qnum);
        printf("Queue :%d\n ",buf.msg_qbytes);
	msg m1,m2,m3;
        qid = msgget(KEY, IPC_CREAT);
        m1.msgtype = 1;
        for(i=0; i<100;i++)
                m1.buffer[i]='a';
        m2.msgtype = 2;
        for(i=0; i<100; i++)
                m2.buffer[i]='b';
        m3.msgtype = 3;
        for(i=0; i<100; i++)
                m3.buffer[i]= 'c';
        i = msgsnd(qid,&m1,sizeof(msg),IPC_NOWAIT);
        printf("%d\n",qid);
        printf("return value of msgsnd of As= %d\n",i);
*/


/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 1234

typedef struct
{
    long messageType;
    char buffer[50];
}MESSAGE;

int main()
{
    int queueID;
    MESSAGE msg;
    struct msqid_ds message_info;

    queueID = msgget(KEY, IPC_CREAT);
    int status = msgctl(queueID, IPC_STAT, &message_info);

    printf("Time of last msgsnd(): %ld \n", message_info.msg_stime);
    printf("Time of last msgrcv(): %ld \n", message_info.msg_rtime);
    printf("Time of creation or last modification by msgctl() %ld \n", message_info.msg_ctime);
    printf("Maximum number of bytes in queue: %ld \n", message_info.msg_qbytes);
    printf("Number of messages in queue is: %ld \n", message_info.msg_qnum);
    return 0;
}*/






















































#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define KEY 1234


int main()
{
        int qid;
        int i;
	struct msqid_ds buf;

        qid = msgget(KEY, IPC_CREAT);
        printf("%d",qid);
        msgctl(qid,IPC_STAT,&buf);
        printf("Queue :%d\n ",buf.msg_qnum);
        printf("Queue :%d\n ",buf.msg_qbytes);
}
