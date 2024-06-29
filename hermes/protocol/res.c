#include <stdlib.h>
#include <string.h>

#include "res.h"

void res__init(res *this, res_status status, int err_no)
{
    this->status = status;
    this->err_no = err_no;
    this->res_ops.serialize = res__serialize;
    this->res_ops.get_size = NULL;
}

size_t res__get_total_size(res *this)
{
    return RESPONSE_HEADER_SIZE + this->res_ops.get_size(this);
}

char *res__serialize(res *this)
{
    size_t total_len = res__get_total_size(this);
    char *buffer = malloc(total_len);
    char status = (char)this->status;
    char err_no = (char)this->err_no;
    int res_len = (int)this->res_ops.get_size(this);

    memset(buffer, 0, total_len);

    memcpy(buffer + 6, &status, sizeof(char));
    memcpy(buffer + 7, &err_no, sizeof(char));
    memcpy(buffer + 8, &res_len, sizeof(int));

    return buffer;
}

res *deserialize_res(void *buffer);

void write_res(int fd, res *res)
{
    char *buffer = res->res_ops.serialize(res);
}
