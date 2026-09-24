#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
	int result;

	/* Create hard link */
	result = link("original.txt" , "hard.txt");

	if(result == 0)
		printf("Hard link created successfully\n");
	else
		perror("link");

	/* Create soft link */

	result =symlink("original.txt","soft.txt");

	if(result == 0)
		printf("Soft link created successfully\n");
	else
		perror("symlink");

	/* Create FIFO */

	result = mkfifo("myfifo",0666);

	if(result == 0)
		printf("FIFO created successfully\n");
	else
		perror("mkfifo");

	return 0;

}
