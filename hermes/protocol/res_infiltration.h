#ifndef RES_INFILTRATION_H
#define RES_INFILTRATION_H

#include "res.h"

typedef struct res_infiltration res_infiltration;

struct res_infiltration
{
    res header;
};

void res_infiltration__init(res_infiltration *this, res_status status, int err_no);
void res_infiltration__destroy(res_infiltration *this);

char *res_infiltration__serialize(res *super);
size_t res_infiltration__get_size(res *super);

void deserialize_res_infiltration(res_infiltration *req, void *buffer);

#endif
