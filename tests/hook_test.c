#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_LEN 32

int main()
{
    char buffer[BUF_LEN] = { 0 };
    int fd;
    
    if ((fd = open("./test_file", O_RDWR)) >= 0)
    {
        read(fd, buffer, BUF_LEN);
        puts(buffer);
        close(fd);
    }
    else
    {
        puts("Couldn't open file.");
    }

    return 0;
}
