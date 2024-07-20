#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int shmid;
    void *ptr;
    char *buff; // or just char buff[100]
    buff=calloc(100,sizeof(int));

    key_t key=ftok("shmfile",10);

    shmid=shmget(key,1024,0666|IPC_CREAT);
    ptr=shmat(shmid,NULL,0);
    printf("Enter message : ");
    scanf("%[^\n]s",buff);
    strcpy(ptr,buff);
    printf("Message sent : %s\n",buff);
    shmdt(ptr);

}