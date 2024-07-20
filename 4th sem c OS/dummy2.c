#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<string.h>

struct {
    long type;
    char text[100];
}msg;

int main(){
    long type;
    key_t key=ftok("filename",10);
    int msgid=msgget(key,0666|IPC_CREAT);
    printf("Enter type to receive : ");
    scanf("%ld",&type);
    msgrcv(msgid,&msg,sizeof(msg.text),type,0);
    printf("Msg received : %s\n",msg.text);
    return 0;
}