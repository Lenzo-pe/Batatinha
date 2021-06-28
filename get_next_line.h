#ifndef	GET_NEXT_LINE
#define GET_NEXT_LINE

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t	get_next_delim(char **line, size_t n, int c, int fd);
int	get_next_line(int fd, char **line);

#endif