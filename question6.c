#include <unistd.h>
int main()
{
    char buffer[100];
    int n;

    n = read(0, buffer, 100);

    if (n == -1)
        return 1;

    write(1, buffer, n);

    return 0;
}
