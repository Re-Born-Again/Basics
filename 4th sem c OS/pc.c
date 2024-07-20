#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>

pthread_t p_tid, c_tid;
int front = -1, rear = -1, array[5];
sem_t mutex, emptyCount, fullCount;

int produce_item();
void insert_item(int);
int remove_item();

void *producer(){
    int item;
    for(int i=0;i<10;i++){
        sem_wait(&emptyCount);
        sem_wait(&mutex);

        item = produce_item();
        printf("Producer entering the critical section.\n");
        insert_item(item);
        printf("Producer inserting an item %d at %d\n", item, rear);
        
        sem_post(&mutex);
        sem_post(&fullCount);
    }
    return NULL;
}

void *consumer(){
    int item;
    sleep(10);
    for(int i=0;i<10;i++){
        sem_wait(&fullCount);
        sem_wait(&mutex);

        sleep(5);
        printf("Consumer entering critical region\n");
        item = remove_item();
        printf("Consumer leaving the critical region\n");
        printf("Consumer consumed an item %d\n", item);

        sem_post(&mutex);
        sem_post(&emptyCount);
    }
    return NULL;
}

int produce_item(){
    static int a = 100;
    return a++;
}

void insert_item(int item){
    rear++;
    rear %= 5;
    array[rear] = item;
}

int remove_item(){
    front++;
    front %= 5;
    int item = array[front];
    return item;
}

int main(){
    int a[8] = {0, 1, 2, 3, 4}, i;

    pthread_t p_tid;
    pthread_t c_tid;
    
    sem_init(&mutex, 0, 1);
    sem_init(&emptyCount, 0, 5);
    sem_init(&fullCount, 0, 0);
    
    pthread_create(&p_tid, NULL, producer, 0);
    pthread_create(&c_tid, NULL, consumer, 0);
    
    pthread_join(p_tid, NULL);
    pthread_join(c_tid, NULL);
    
    return 0;
}