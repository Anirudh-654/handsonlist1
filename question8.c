#include <stdio.h>

int main()
{
    FILE *file;
    char buffer[100];

    file = fopen("original.txt", "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}
