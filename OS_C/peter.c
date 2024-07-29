#include <stdio.h>
#include <pthread.h>

int turn, flag[2];

int tot = 100, t1 = 0, t2 = 0;

void *client(void *arg)
{
    int ser = *(int *)arg;
    int op, n;
    while (1)
    {

        flag[0] = 1;
        turn = 1;
        while (turn == 1 && flag[1] == 1)
            ;

        printf("\nLOADING....\n");
        printf("Available tickets (client) : %d\n", tot);
        printf("1.Book 2.Cancel 3.Exit\nEnter option (client) : ");
        scanf("%d", &op);
        if (op == 3)
        {
            printf("Exited\n");
            flag[0] = 0;
            break;
        }
        printf("Enter no. tickets (client) : ");
        scanf("%d", &n);
        if (op == 1 && n <= tot)
        {
            tot -= n;
            ser += n;
            printf("%d tickets booked successfully!\n", n);
        }
        else if (op == 1 && n > tot)
        {
            printf("Invalid no. tickets!\n");
        }
        else if (op == 2 && n <= ser)
        {
            tot += n;
            ser -= n;
            printf("%d tickets cancelled successfully!\n", n);
        }
        else if (op == 2 && n > ser)
        {
            printf("Invalid no. tickets!\n");
        }
        else if (op != 1 && op != 2)
        {
            printf("Invalid option!\n");
        }
        else
        {
            printf("Error!\n");
        }

        printf("Available tickets after request (client) : %d\n", tot);

        flag[0] = 0;
    }
    pthread_exit(NULL);
}

void *server(void *arg)
{
    int ser = *(int *)arg;
    int op, n;
    while (1)
    {

        flag[1] = 1;
        turn = 0;
        while (turn == 0 && flag[0] == 1)
            ;

        printf("\nLOADING....\n");

        printf("Available tickets (server) : %d\n", tot);
        printf("1.Book 2.Cancel 3.Exit\nEnter option (server) : ");
        scanf("%d", &op);
        if (op == 3)
        {
            printf("Exited\n");
            flag[1] = 0;
            break;
        }
        printf("Enter no. tickets (server) : ");
        scanf("%d", &n);
        if (op == 1 && n <= tot)
        {
            tot -= n;
            ser += n;
            printf("%d tickets booked successfully!\n", n);
        }
        else if (op == 1 && n > tot)
        {
            printf("Invalid no. tickets!\n");
        }
        else if (op == 2 && n <= ser)
        {
            tot += n;
            ser -= n;
            printf("%d tickets cancelled successfully!\n", n);
        }
        else if (op == 2 && n > ser)
        {
            printf("Invalid no. tickets!\n");
        }
        else if (op != 1 && op != 2)
        {
            printf("Invalid option!\n");
        }
        else
        {
            printf("Error!\n");
        }

        printf("Available tickets after request (server) : %d\n", tot);

        flag[1] = 0;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t p1, p2;

    pthread_create(&p1, NULL, client, &t1);
    pthread_create(&p2, NULL, server, &t1);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    pthread_exit(NULL);
}