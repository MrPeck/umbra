#ifndef ACTIONS_H
#define ACTIONS_H

#include "c2_prot.h"

void exfiltrate_file(int sockfd, struct exf_req *req);
void infiltrate_file(int sockfd, struct inf_req *req);

#endif