#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    pid_t pid;
    FILE *fp;
    time_t now;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        printf("Parent exiting. Daemon started.\n");
        return 0;
    }

    if (setsid() == -1)
    {
        perror("setsid");
        return 1;
    }

    chdir("/");
    umask(0);

    while (1)
    {
        fp = fopen("/tmp/question30_daemon.txt", "a");

        if (fp != NULL)
        {
            now = time(NULL);
            fprintf(fp, "Daemon running: %s", ctime(&now));
            fclose(fp);
        }

        sleep(5);
    }

    return 0;
}
