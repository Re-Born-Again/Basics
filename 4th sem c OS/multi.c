#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct demo
{
    int a;
    char b;
    char c[10];
};

void *struct_fn(void *arg)
{
    struct demo dd = *(struct demo *)arg;
    printf("Thread values are, a:%d , b:%c , c:%s \n", dd.a, dd.b, dd.c);
    pthread_exit(NULL);
}

void *int_fn(void *arg)
{
    int val = *(int *)arg;
    printf("Value of int : %d\n", val);
    pthread_exit(NULL);
}

void *char_fn(void *arg)
{
    int val = *(char *)arg;
    printf("Char value : %c\n", val);
    pthread_exit(NULL);
}

void *string_fn(void *arg)
{
    char *val = (char *)arg;
    printf("String value : %s\n", val);
    pthread_exit(NULL);
}

int main()
{
    struct demo d[2];
    pthread_t p1, p2, p3, p4, p5;

    d[0].a = 0;
    d[0].b = 'a';
    strcpy(d[0].c, "aaa");

    d[1].a = 1;
    d[1].b = 'b';
    strcpy(d[1].c, "bbb");

    pthread_create(&p1, NULL, struct_fn, &d[0]);
    pthread_join(p1, NULL);

    pthread_create(&p2, NULL, struct_fn, &d[1]);
    pthread_join(p2, NULL);

    char *a = "string";

    pthread_create(&p3, NULL, string_fn, a);
    pthread_join(p3, NULL);

    int n = 10;

    pthread_create(&p4, NULL, int_fn, &n);
    pthread_join(p4, NULL);

    char c = 'x';

    pthread_create(&p5, NULL, char_fn, &c);
    pthread_join(p5, NULL);

    pthread_exit(NULL);
}