#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int count = 1;
    char filename[100];

    while (1)
    {
        for (int i = 0; i < 5; i++)
        {
            sprintf(filename, "file%d.txt", count);

            fd = creat(filename, 0644);

            if (fd == -1)
            {
                perror("creat");
                return 1;
            }

            printf("Created %s with FD %d\n", filename, fd);

            count++;
        }

        sleep(2);
    }

    return 0;
}
