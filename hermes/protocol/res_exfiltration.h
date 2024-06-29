#ifndef RES_EXFILTRATION_H
#define RES_EXFILTRATION_H

#include "res.h"

typedef struct res_exfiltration res_exfiltration;

struct res_exfiltration
{
    res header;
    char *data;
    size_t data_len;
};

void res_exfiltration__init(res_exfiltration *this, res_status status, int err_no, char *data, size_t data_len);
void res_exfiltration__destroy(res_exfiltration *this);

char *res_exfiltration__serialize(res *super);
size_t res_exfiltration__get_size(res *super);

void deserialize_res_exfiltration(res_exfiltration *req, void *buffer);

#endif
