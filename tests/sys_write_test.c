#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char buffer[] = "Hello, world!\n";
    int fd;
    
    if ((fd = open("./test_file", O_RDWR)) >= 0)
    {
        write(fd, buffer, strlen(buffer));
        close(fd);
    }
    else
    {
        puts("File not found...");
    }

    return 0;
}
