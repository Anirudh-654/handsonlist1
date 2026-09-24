#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int records[3] = {100, 200, 300};

    fd = open("records.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, records, sizeof(records));

    close(fd);

    printf("Three records created.\n");

    return 0;
}
