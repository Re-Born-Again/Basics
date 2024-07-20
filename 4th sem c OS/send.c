#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct mq{
 long type;
 char text[100];
}msg;

int main(){

int msgid;

msgid=msgget(8060,0666|IPC_CREAT);
printf("Enter message type : ");
scanf("%ld",&msg.type);
getchar();
printf("Enter message : ");
scanf("%[^\n]s",msg.text);
msgsnd(msgid,&msg,strlen(msg.text)+1,0);
printf("%s Data sent successfully\n",msg.text);
return 0;

}