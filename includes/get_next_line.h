#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libjr.h"

#define PERMS 0666
#define BUFFER_SIZE 32

int	get_next_line(int fd, char **line);

#endif
