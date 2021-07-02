#ifndef	GET_NEXT_LINE_BONUS
#define GET_NEXT_LINE_BONUS

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	short int		index;
	char			*saved;
	struct s_list	*next;
}	t_list;

ssize_t	get_next_delim(char **line, size_t n, int c, int fd);
int	get_next_line(int fd, char **line);

#endif