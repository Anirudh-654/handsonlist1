#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before exec()\n");

    execl("./hello", "hello", "Anirudh", (char *)NULL);

    perror("execl");

    return 1;
}
