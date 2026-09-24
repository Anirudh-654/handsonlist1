#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int main()
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        int is_pid = 1;
        int i = 0;

        /* Check whether directory name contains only digits */
        while (entry->d_name[i] != '\0')
        {
            if (!isdigit(entry->d_name[i]))
            {
                is_pid = 0;
                break;
            }

            i++;
        }

        if (is_pid)
        {
            int pid = atoi(entry->d_name);
            char path[100];
            char line[256];

            sprintf(path, "/proc/%d/status", pid);

            FILE *fp = fopen(path, "r");

            if (fp == NULL)
                continue;

            printf("\nPID: %d\n", pid);

            while (fgets(line, sizeof(line), fp) != NULL)
            {
                if (strncmp(line, "Name:", 5) == 0 ||
                    strncmp(line, "Pid:", 4) == 0 ||
                    strncmp(line, "PPid:", 5) == 0 ||
                    strncmp(line, "State:", 6) == 0)
                {
                    printf("%s", line);
                }
            }

            fclose(fp);
        }
    }

    closedir(dir);

    return 0;
}
