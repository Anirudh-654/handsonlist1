#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child process: PID = %d\n", getpid());
    }
    else
    {
        printf("Parent process: PID = %d, Child PID = %d\n",
               getpid(), pid);
    }

    return 0;
}
