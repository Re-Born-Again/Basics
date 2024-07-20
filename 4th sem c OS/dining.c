#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (philosopher_id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS
#define RIGHT (philosopher_id + 1) % NUM_PHILOSOPHERS

int state[NUM_PHILOSOPHERS];
sem_t mutex;
sem_t forks[NUM_PHILOSOPHERS];

void test(int philosopher_id) {
    if (state[philosopher_id] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[philosopher_id] = EATING;
        printf("Philosopher %d is eating\n", philosopher_id);
        sem_post(&forks[philosopher_id]);
    }
}

void pickup_forks(int philosopher_id) {
    sem_wait(&mutex);
    state[philosopher_id] = HUNGRY;
    printf("Philosopher %d is hungry\n", philosopher_id);
    test(philosopher_id);
    sem_post(&mutex);
    sem_wait(&forks[philosopher_id]);
}

void putdown_forks(int philosopher_id) {
    sem_wait(&mutex);
    state[philosopher_id] = THINKING;
    printf("Philosopher %d is thinking\n", philosopher_id);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void* philosopher(void* arg) {
    int philosopher_id = *(int*)arg;
    while (1) {
        sleep(rand() % 5 + 1); // Thinking
        pickup_forks(philosopher_id);
        sleep(rand() % 5 + 1); // Eating
        putdown_forks(philosopher_id);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];
    int i;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    for (i = 0; i < NUM_PHILOSOPHERS; ++i) {
        sem_init(&forks[i], 0, 0);
    }

    // Create philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; ++i) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

    // Wait for threads to finish (won't happen in this example)
    for (i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    for (i = 0; i < NUM_PHILOSOPHERS; ++i) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
