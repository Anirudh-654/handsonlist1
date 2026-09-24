#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, newfd;

    fd = open("fcntl.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    newfd = fcntl(fd, F_DUPFD, 10);

    if (newfd == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Original FD = %d\n", fd);
    printf("Duplicate FD = %d\n", newfd);

    write(fd, "HELLO\n", 6);
    write(newfd, "WORLD\n", 6);

    close(fd);
    close(newfd);

    return 0;
}
