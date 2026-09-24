#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child process: PID = %d\n", getpid());
        printf("Parent PID before parent exits = %d\n", getppid());

        sleep(5);

        printf("Parent PID after parent exits = %d\n", getppid());
        printf("Child is now an orphan process.\n");

        sleep(10);
    }
    else
    {
        printf("Parent process: PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);

        printf("Parent exiting...\n");
        exit(0);
    }

    return 0;
}
