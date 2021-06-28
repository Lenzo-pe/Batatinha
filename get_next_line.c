#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{

	return (get_next_delim(line, BUFFER_SIZE, '\n', fd));
}
