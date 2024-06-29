#include <string.h>
#include <stdlib.h>

#include "req_exfiltration.h"

#define REQ_EXFILTRATION_HEADER_SIZE 8

void req_exfiltration__init(req_exfiltration *this, char *path)
{
    size_t path_len = strlen(path) + 1;

    req__init((req *)this, EXF_FILE);

    this->header.req_ops.serialize = req_exfiltration__serialize;
    this->header.req_ops.get_size = req_exfiltration__get_size;

    this->path = malloc(path_len);
    strcpy(this->path, path);
}

void req_exfiltration__destroy(req_exfiltration *this)
{
    free(this->path);
}

char *req_exfiltration__serialize(req *super)
{
    req_exfiltration *this = (req_exfiltration *)super;
    char *buffer = req__serialize(super);
    short path_len = (short)(strlen(this->path) + 1);

    memcpy(buffer + REQUEST_HEADER_SIZE, &path_len, sizeof(short));
    memcpy(((char *)buffer + REQUEST_HEADER_SIZE + 8), this->path, path_len);

    return buffer;
}

size_t req_exfiltration__get_size(req *super)
{
    req_exfiltration *this = (req_exfiltration *)super;

    return strlen(this->path) + 1 + REQ_EXFILTRATION_HEADER_SIZE;
}

void deserialize_req_exfiltration(req_exfiltration *req, void *buffer)
{
    short path_len;
    char *path;

    memcpy(&path_len, buffer, 2);

    path = malloc(path_len);
    memcpy(path, buffer + 8, path_len);

    req_exfiltration__init(req, path);

    free(path);
}

