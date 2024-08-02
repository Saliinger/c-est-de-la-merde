#ifndef GNL_H
#define GNL_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef BS
# define BS 42
#endif

char *get_next_line(int fd);

#endif