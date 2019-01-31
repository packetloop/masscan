#include "stats.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void
check_file_size(const char *filename, size_t sz)
{
    int fd;
    struct stat st;

    if ((fd = open(filename, O_RDWR, S_IRUSR | S_IWUSR)) == -1) {
        fprintf(stderr, "Cannot open file \"%s\"\n", filename);
        exit(1);
    }

    if(fstat(fd, &st) < 0) {
        fprintf(stderr, "Error in fstat(\"%s\")\n", filename);
        exit(1);
    }

    if(sz != st.st_size) {
        fprintf(stderr, "File \"%s\" is not initialised(size %zu is required).\n", filename, sz);
        exit(1);
    }

    close(fd);
}
