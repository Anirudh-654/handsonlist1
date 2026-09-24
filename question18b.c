#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd;
    int record_no;
    int record;
    off_t offset;
    struct flock lock;

    if (argc != 2)
    {
        printf("Usage: %s <record_number>\n", argv[0]);
        return 1;
    }

    record_no = atoi(argv[1]);

    if (record_no < 1 || record_no > 3)
    {
        printf("Record number must be 1, 2, or 3\n");
        return 1;
    }

    fd = open("records.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    offset = (record_no - 1) * sizeof(int);

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = sizeof(int);

    printf("Trying to lock Record %d for reading...\n", record_no);

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock acquired for Record %d\n", record_no);

    lseek(fd, offset, SEEK_SET);

    read(fd, &record, sizeof(int));

    printf("Record %d value = %d\n", record_no, record);

    printf("Read lock is active. Press Enter to release it.\n");

    getchar();

    lock.l_type = F_UNLCK;

    fcntl(fd, F_SETLK, &lock);

    printf("Read lock released for Record %d\n", record_no);

    close(fd);

    return 0;
}
