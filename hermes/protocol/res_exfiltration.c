#include <stdlib.h>
#include <string.h>

#include "res_exfiltration.h"

#define RES_EXFILTRATION_HEADER_SIZE 8

void res_exfiltration__init(res_exfiltration *this, res_status status, int err_no, char *data, size_t data_len)
{
    res__init((res *) this, status, err_no);

    this->header.res_ops.serialize = res_exfiltration__serialize;
    this->header.res_ops.get_size = res_exfiltration__get_size;

    if (data_len > 0)
    {
        this->data = malloc(data_len);
        memcpy(this->data, data, data_len);
    }
    else
    {
        this->data = NULL;
    }

    this->data_len = data_len;
}

void res_exfiltration__destroy(res_exfiltration *this)
{
    free(this->data);
}

char *res_exfiltration__serialize(res *super)
{
    res_exfiltration *this = (res_exfiltration *) super;
    char *buffer = res__serialize(super);
    int data_len = this->data_len;

    memcpy(buffer + RESPONSE_HEADER_SIZE, &data_len, sizeof(int));
    memcpy(buffer + RESPONSE_HEADER_SIZE + 8, this->data, this->data_len);

    return buffer;
}

size_t res_exfiltration__get_size(res *super)
{
    res_exfiltration *this = (res_exfiltration *) super;

    return this->data_len + RES_EXFILTRATION_HEADER_SIZE;
}

void deserialize_res_exfiltration(res_exfiltration *req, void *buffer);
