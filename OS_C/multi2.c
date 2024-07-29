#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct demo{
    int id;
    int *arr;
};


void* sortarr(void* arg){
    struct demo a=*(struct demo*)arg;
    printf("Thread %d : ",a.id);
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(a.arr[j]>a.arr[j+1]){
                int temp=a.arr[j];
                a.arr[j]=a.arr[j+1];
                a.arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",a.arr[i]);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t p[2];
    struct demo d[2];

    d[0].id=1;
    d[0].arr=calloc(5,sizeof(int));
    int k=0;
    for(int i=5;i>0;i--){
        d[0].arr[k]=i;
        k++;
    }

    d[1].id=2;
    d[1].arr=calloc(5,sizeof(int));
    d[1].arr[0]=9;
    d[1].arr[1]=8;
    d[1].arr[2]=7;
    d[1].arr[3]=6;
    d[1].arr[4]=5;

    pthread_create(&p[0],NULL,sortarr,&d[0]);
    pthread_join(p[0],NULL);

    pthread_create(&p[1],NULL,sortarr,&d[1]);
    pthread_join(p[1],NULL);

    free(d[0].arr);
    free(d[1].arr);

    pthread_exit(NULL);
}