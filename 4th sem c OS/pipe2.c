#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define r1 fd1[0]
#define w1 fd1[1]
#define r2 fd2[0]
#define w2 fd2[1]

int main()
{
    int c1, c2, fd1[2], fd2[2];
    char buffer1[100], buffer2[100];

    pipe(fd1);
    pipe(fd2);

    c1 = fork();
    if (c1 == 0)
    { // child 1
        printf("Inside c1\n");
        close(r1);
        close(w2);

        write(w1, "Hello from c1!", sizeof("Hello from c1!"));
        printf("c1 wrote msg\n");
        close(w1);

        read(r2, buffer2, sizeof(buffer2));
        printf("c1 Read %s\n", buffer2);
        close(r2);
    }
    else
    { // child 2 or parent
        c2 = fork();
        if (c2 == 0)
        {
            printf("Inside C2\n");
            close(w1);
            close(r2);

            read(r1, buffer2, sizeof(buffer2));
            printf("c2 Read %s\n", buffer2);
            close(r1);

            write(w2, "Hello from c2!", sizeof("Hello from c2!"));
            printf("c2 wrote msg\n");
            close(w2);
        }
        else
        { // parent
            wait(0);
            printf("Inside Parent\n");
        }
    }
}