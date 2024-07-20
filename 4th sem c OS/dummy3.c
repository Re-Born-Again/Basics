#include<stdio.h>
#include<pthread.h>

void* disp(void* arg){
    char *buff=(char*)arg;
    printf("Inside disp : %s\n",buff);
    pthread_exit(NULL);
}

int main(){
    pthread_t p;
    char buff[100]="Hello threads!";

    pthread_create(&p,NULL,disp,buff);
    pthread_join(p,NULL);
    return 0;
}