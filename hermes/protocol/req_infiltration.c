#include <string.h>
#include <stdlib.h>

#include "req_infiltration.h"

#define REQ_INFILTRATION_HEADER_SIZE 8

void req_infiltration__init(req_infiltration *this, char *path, char *data, size_t data_len, short perms)
{
    size_t path_len = strlen(path) + 1;

    req__init((req *)this, INF_FILE);

    this->header.req_ops.serialize = req_infiltration__serialize;
    this->header.req_ops.get_size = req_infiltration__get_size;

    this->path = malloc(path_len);
    memcpy(this->path, path, path_len);

    this->data = malloc(data_len);
    memcpy(this->data, data, data_len);

    this->perms = perms;
    this->data_len = data_len;
}

void req_infiltration__destroy(req_infiltration *this)
{
    free(this->path);
    free(this->data);
}

char *req_infiltration__serialize(req *super)
{
    req_infiltration *this = (req_infiltration *)super;
    char *buffer = req__serialize(super);
    short path_len = (short)strlen(this->path) + 1;
    short perms = (short)this->perms;
    int data_len = (int)this->data_len;

    memcpy(buffer + REQUEST_HEADER_SIZE, &path_len, sizeof(short));
    memcpy(buffer + REQUEST_HEADER_SIZE + 2, &perms, sizeof(short));
    memcpy(buffer + REQUEST_HEADER_SIZE + 4, &data_len, sizeof(int));
    memcpy(buffer + REQUEST_HEADER_SIZE + 8, this->path, path_len);
    memcpy(buffer + REQUEST_HEADER_SIZE + 8 + path_len, this->data, this->data_len);

    return buffer;
}

size_t req_exfiltration__get_size(req *super)
{
    req_infiltration *this = (req_infiltration *)super;

    return strlen(this->path) + 1 + this->data_len + REQ_INFILTRATION_HEADER_SIZE;
}

void deserialize_req_infiltration(req_infiltration *req, void *buffer)
{
    short path_len;
    short perms;
    int data_len;
    char *path;
    char *data;

    memcpy(&path_len, buffer, sizeof(short));

    path = malloc(path_len);
    memcpy(path, buffer + 8, path_len);

    memcpy(&perms, buffer + 2, sizeof(short));

    memcpy(&data_len, buffer + 4, sizeof(int));

    data = malloc(data_len);
    memcpy(data, buffer + 8 + path_len, data_len);

    req_infiltration__init(req, path, data, (size_t)data_len, perms);

    free(path);
    free(data);
}
