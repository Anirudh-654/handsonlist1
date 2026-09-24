#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello from the executable program!\n");

    if (argc > 1)
        printf("Input received: %s\n", argv[1]);

    return 0;
}
