#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_LEN 32

int main()
{
    char buffer[BUF_LEN];
    int fd;
    
    if ((fd = open("./test_file", O_RDONLY)) != -1)
    {
        read(fd, buffer, BUF_LEN);
        puts(buffer);
        close(fd);
    }
    else
    {
        puts("File not found...");
    }

    return 0;
}
