#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    pid_t pid;

    fd = open("forkfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        write(fd, "Child process writing\n", 22);
    }
    else
    {
        write(fd, "Parent process writing\n", 23);
    }

    close(fd);

    return 0;
}
