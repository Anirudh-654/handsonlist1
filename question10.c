#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    off_t position;

    fd = open("seekfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, "ABCDEFGHIJ", 10);

    position = lseek(fd, 10, SEEK_CUR);

    if (position == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    write(fd, "1234567890", 10);

    close(fd);

    return 0;
}
/*
How to compile and run:

gcc question10.c -o question10
./question10

Check the file contents in octal/character format:

od -c seekfile.txt

Check the file contents as hexadecimal bytes:

od -An -tx1 seekfile.txt

Check the file size:

ls -l seekfile.txt
*/