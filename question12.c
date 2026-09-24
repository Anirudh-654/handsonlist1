#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int flags;
    int mode;

    fd = open("test.txt", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);

    if (flags == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    mode = flags & O_ACCMODE;

    if (mode == O_RDONLY)
        printf("Read Only\n");
    else if (mode == O_WRONLY)
        printf("Write Only\n");
    else if (mode == O_RDWR)
        printf("Read Write\n");

    close(fd);

    return 0;
}
