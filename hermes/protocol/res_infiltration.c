#include "res_infiltration.h"

void res_infiltration__init(res_infiltration *this, res_status status, int err_no)
{
    res__init((res *)this, status, err_no);

    this->header.res_ops.serialize = res_infiltration__serialize;
    this->header.res_ops.get_size = res_infiltration__get_size;
}

void res_infiltration__destroy(res_infiltration *this) { }

char *res_infiltration__serialize(res *super)
{
    res_infiltration *this = (res_infiltration *)this;
    char *buffer = res__serialize(super);

    return buffer;
}

size_t res_infiltration__get_size(res *super)
{
    return 0;
}

void deserialize_res_infiltration(res_infiltration *req, void *buffer);
