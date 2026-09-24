#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[100];
    int n;

    source = open("original.txt", O_RDONLY);

    if (source == -1)
    {
        perror("source");
        return 1;
    }

    destination = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (destination == -1)
    {
        perror("destination");
        close(source);
        return 1;
    }

    while ((n = read(source, buffer, 100)) > 0)
    {
        write(destination, buffer, n);
    }

    close(source);
    close(destination);

    printf("File copied successfully\n");

    return 0;
}
