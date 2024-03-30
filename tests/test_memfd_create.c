#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void create_anonymous_file(char* buf, int size, char *const argv[], char *const envp[]) {
	//memfd_create(const char *name, unsigned int flags);
	int fd;

	char temp_name[] = "temp_name";

	// create anonymous file
	fd = memfd_create(temp_name, MFD_ALLOW_SEALING);
	if (fd == -1) {
		// todo: fix with normal error 
		printf("error 1..");
		return;
	}

	int bytes_written = write(fd, buf, size);
	if (bytes_written == -1) {
		// todo: fix with normal error 
		printf("error 2..");
		return;
	}

	// execute the elf
	// fexecve(int fd, char *const argv[], char *const envp[]);
	if (fexecve(fd, (char*[]){NULL}, (char*[]){NULL}) == -1) {
		// todo: fix with normal error 
		printf("%d", errno);
		return;
	}

	printf("success!");
}

int main() {

	char buf[] = "#!/bin/bash\nsleep 123";
	int size = sizeof(buf);

	create_anonymous_file(buf, size, NULL, NULL);

	return 1;
}