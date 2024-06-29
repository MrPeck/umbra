#ifndef REQ_EXFILTRATION_H
#define REQ_EXFILTRATION_H

#include "req.h"

typedef struct req_exfiltration req_exfiltration;

struct req_exfiltration
{
    req header;
    char *path;
};

void req_exfiltration__init(req_exfiltration *this, char *path);
void req_exfiltration__destroy(req_exfiltration *this);

char *req_exfiltration__serialize(req *this);
size_t req_exfiltration__get_size(req *this);

void deserialize_req_exfiltration(req_exfiltration *req, void *buffer);

#endif
