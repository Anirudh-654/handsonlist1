#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, newfd;

    fd = open("dup2.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    newfd = dup2(fd, 10);

    if (newfd == -1)
    {
        perror("dup2");
        close(fd);
        return 1;
    }

    write(fd, "HELLO\n", 6);
    write(newfd, "WORLD\n", 6);

    close(fd);
    close(newfd);

    return 0;
}
