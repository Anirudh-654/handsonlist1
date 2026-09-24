#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int ticket;
    struct flock lock;

    fd = open("ticket.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Waiting for write lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock acquired.\n");

    lseek(fd, 0, SEEK_SET);

    if (read(fd, &ticket, sizeof(ticket)) != sizeof(ticket))
    {
        perror("read");
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        return 1;
    }

    ticket++;

    printf("Reserved ticket number = %d\n", ticket);

    lseek(fd, 0, SEEK_SET);

    if (write(fd, &ticket, sizeof(ticket)) != sizeof(ticket))
    {
        perror("write");
    }

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Write lock released.\n");

    close(fd);

    return 0;
}
