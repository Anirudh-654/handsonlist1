#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>

int main()
{
    unsigned long long start, end;
    pid_t pid;

    start = __rdtsc();

    pid = getpid();

    end = __rdtsc();

    printf("PID = %d\n", pid);
    printf("Time taken by getpid() = %llu CPU cycles\n",
           end - start);

    return 0;
}
