#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy = ");

    if (policy == SCHED_OTHER)
        printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("SCHED_RR\n");

    param.sched_priority = 10;

    if (sched_setscheduler(0, SCHED_RR, &param) == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    policy = sched_getscheduler(0);

    printf("New scheduling policy = ");

    if (policy == SCHED_OTHER)
        printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("SCHED_RR\n");

    return 0;
}
