#ifndef RES_H
#define RES_H

#include <stdio.h>

#define RESPONSE_HEADER_SIZE 16

typedef struct res_operations res_operations;
typedef struct res res;
typedef enum res_status res_status;

enum res_status
{
    GOOD = 0,
    OPEN_ERROR = 1,
    READ_ERROR = 2,
    WRITE_ERROR = 3,
    STAT_ERROR = 4,
    NOT_FILE = 5,
    NOT_DIRECTORY = 6
};

struct res_operations
{
    char *(*serialize)(res *super);
    size_t (*get_size)(res *super);
};

struct res
{
    res_status status;
    int err_no;
    res_operations res_ops;
};

void res__init(res *this, res_status status, int err_no);

size_t res__get_total_size(res *this);

char *res__serialize(res *this);

res *deserialize_res(void *buffer);
void write_res(int fd, res *res);

#endif
