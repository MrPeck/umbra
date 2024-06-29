#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "req.h"
#include "req_exfiltration.h"
#include "req_infiltration.h"

void req__init(req *this, req_type type)
{
    this->type = type;
    this->req_ops.serialize = req__serialize;
    this->req_ops.get_size = NULL;
}

size_t req__get_total_size(req *this)
{
    return REQUEST_HEADER_SIZE + this->req_ops.get_size(this);
}

char *req__serialize(req *this)
{
    int req_len = this->req_ops.get_size(this);
    size_t total_len = req__get_total_size(this);
    char *buffer = malloc(total_len);
    char type = (char)this->type;

    memset(buffer, 0, total_len);

    memcpy(buffer + 7, &type, sizeof(char));
    memcpy(buffer + 8, &req_len, sizeof(int));

    return buffer;
}

void deserialize_req_header(req *header, char *buffer)
{
    char type;
    size_t req_len;

    memcpy(&type, buffer + 7, sizeof(char));
    memcpy(&req_len, buffer + 8, sizeof(int));

    header->type = (req_type)type;
}

req *deserialize_req(char *buffer)
{
    req header_tmp;
    req *req;

    deserialize_req_header(&header_tmp, buffer);

    switch (header_tmp.type) {
        case EXF_FILE:
            req = malloc(sizeof(req_exfiltration));
            deserialize_req_exfiltration((req_exfiltration *)req, buffer + REQUEST_HEADER_SIZE);
            break;

        case INF_FILE:
            req = malloc(sizeof(req_infiltration));
            deserialize_req_infiltration((req_infiltration *)req, buffer + REQUEST_HEADER_SIZE);
            break;

        case SUICIDE:
            break;
    }

    return req;
}

req *read_req(int fd)
{
    req *header = malloc(sizeof(req));
    char *buffer = malloc(REQUEST_HEADER_SIZE);

    memset(header, 0, sizeof(req));
    memset(buffer, 0, REQUEST_HEADER_SIZE);

    read(fd, buffer, REQUEST_HEADER_SIZE);

    deserialize_req_header(header, buffer);

    buffer = realloc(buffer, REQUEST_HEADER_SIZE + header->req_ops.get_size(header));

    header = deserialize_req(buffer);

    free(buffer);

    return header;
}