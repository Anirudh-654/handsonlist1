#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat st;

    if (stat("original.txt", &st) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode number       : %lu\n", st.st_ino);
    printf("Hard links         : %lu\n", st.st_nlink);
    printf("User ID            : %u\n", st.st_uid);
    printf("Group ID           : %u\n", st.st_gid);
    printf("File size          : %ld bytes\n", st.st_size);
    printf("Block size         : %ld bytes\n", st.st_blksize);
    printf("Number of blocks   : %ld\n", st.st_blocks);

    printf("Last access time   : %s", ctime(&st.st_atime));
    printf("Last modified time : %s", ctime(&st.st_mtime));
    printf("Last change time   : %s", ctime(&st.st_ctime));

    return 0;
}
