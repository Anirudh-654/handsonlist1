#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set readfds;
    struct timeval timeout;
    int result;
    char buffer[100];
    int n;

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    result = select(1, &readfds, NULL, NULL, &timeout);

    if (result > 0)
    {
        if (FD_ISSET(0, &readfds))
        {
            n = read(0, buffer, sizeof(buffer));

            if (n > 0)
            {
                printf("Data is available within 10 seconds\n");
                printf("Input received: %.*s", n, buffer);
            }
        }
    }
    else if (result == 0)
    {
        printf("No data available within 10 seconds\n");
    }
    else
    {
        perror("select");
    }

    return 0;
}
