#ifndef ACTIONS_H
#define ACTIONS_H

void exfiltrate_file(int sockfd, char *path);
void infiltrate_file(int sockfd, char *path, char *content, size_t size, int perm);

#endif