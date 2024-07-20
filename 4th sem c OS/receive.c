#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct mq{
 long type;
 char text[100];
}msg;

int main(){

int msgid,type;

msgid=msgget(8060,0666|IPC_EXCL);
printf("Enter type to receive : ");
scanf("%d",&type);
msgrcv(msgid,&msg,sizeof(msg.text),type,0);
printf("Received Message type : %ld\n",msg.type);
printf("Received Message : %s\n",msg.text);

printf("Data received successfully\n");

// msgctl(msgid,IPC_RMID,NULL); this will delete the queue after single use of this program
return 0;

}