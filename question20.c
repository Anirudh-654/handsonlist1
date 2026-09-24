#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main()
{
    int before, after;

    before = getpriority(PRIO_PROCESS, 0);

    printf("Process ID = %d\n", getpid());
    printf("Nice value before = %d\n", before);

    errno = 0;

    if (nice(5) == -1 && errno != 0)
    {
        perror("nice");
        return 1;
    }

    after = getpriority(PRIO_PROCESS, 0);

    printf("Nice value after = %d\n", after);

    return 0;
}
