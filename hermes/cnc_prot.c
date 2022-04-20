#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "cnc_prot.h"

struct exf_format_res *get_exf_from_cnc_res(struct cnc_response *res)
{
    return (struct exf_format_res *)res->data;
}

struct exf_format_req *get_exf_from_cnc_req(struct cnc_request *req)
{
    return (struct exf_format_req *)req->data;
}

struct inf_format_res *get_inf_from_cnc_res(struct cnc_response *res)
{
    return (struct inf_format_res *)res->data;
}

struct inf_format_req_path *get_inf_path_from_cnc_req(struct cnc_request *req)
{
    return (struct inf_format_req_path *)req->data;
}

struct inf_format_req_content *get_inf_content_from_cnc_req(struct cnc_request *req)
{
    struct inf_format_req_path *tmp = get_inf_path_from_cnc_req(req);
    return (struct inf_format_req_content *)&tmp->path[tmp->path_len];
}

struct cnc_response *cnc_exf_res_init(uint32_t file_size, uint8_t err)
{
    struct cnc_response *res;
    struct exf_format_res *exf_res;

    uint32_t res_len = sizeof(struct cnc_response) + sizeof(struct exf_format_res) + file_size;

    res = malloc(res_len);
    memset(res, 0, res_len);

    res->res_len = res_len;
    exf_res = get_exf_from_cnc_res(res);
    exf_res->content_len = file_size;
    exf_res->err = err;

    return res;
}

struct cnc_response *cnc_inf_res_init(uint8_t status)
{
    struct cnc_response *res;
    struct inf_format_res *inf_res;

    uint32_t res_len = sizeof(struct cnc_response) + sizeof(struct inf_format_res);

    res = malloc(res_len);
    memset(res, 0, res_len);

    inf_res = get_inf_from_cnc_res(res);
    inf_res->status = status;

    return res;
}
