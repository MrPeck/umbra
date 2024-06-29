#ifndef REQ_INFILTRATION_H
#define REQ_INFILTRATION_H

#include "req.h"

typedef struct req_infiltration req_infiltration;

struct req_infiltration
{
    req header;
    char *path;
    char *data;
    size_t data_len;
    short perms;
};

void req_infiltration__init(req_infiltration *this, char *path, char *data, size_t data_len, short perms);
void req_infiltration__destroy(req_infiltration *this);

char *req_infiltration__serialize(req *super);
size_t req_infiltration__get_size(req *super);

void deserialize_req_infiltration(req_infiltration *req, void *buffer);

#endif
