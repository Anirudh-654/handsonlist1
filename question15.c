#include <stdio.h>

extern char **environ;

int main()
{
    char **env;

    env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
