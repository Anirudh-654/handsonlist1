#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t child1, child2, child3;
    int status;

    child1 = fork();

    if (child1 == 0)
    {
        printf("Child 1: PID = %d\n", getpid());
        sleep(3);
        printf("Child 1 exiting\n");
        exit(1);
    }

    child2 = fork();

    if (child2 == 0)
    {
        printf("Child 2: PID = %d\n", getpid());
        sleep(5);
        printf("Child 2 exiting\n");
        exit(2);
    }

    child3 = fork();

    if (child3 == 0)
    {
        printf("Child 3: PID = %d\n", getpid());
        sleep(7);
        printf("Child 3 exiting\n");
        exit(3);
    }

    printf("Parent: PID = %d\n", getpid());
    printf("Parent waiting for Child 2: PID = %d\n", child2);

    waitpid(child2, &status, 0);

    printf("Parent finished waiting for Child 2\n");

    return 0;
}
