#include "get_next_line.h"

void	ft_strdel(char **str)
{
	if (!(str && *str))
		return ;
	free(*str);
	*str = NULL;
}

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == 0)
		return ((char *)str);
	return (NULL);
}

static void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!dest && !src)
		return (dest);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (num--)
		*str1++ = *str2++;
	return (dest);
}

static size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (maxlen > i && str[i])
		i++;
	return (i);
}

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strclen(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	return (ft_memcpy(ptr, str, len));
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			maxlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	maxlen = ft_strnlen(s, len);
	ptr = (char *)malloc(sizeof(char) * (maxlen + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, (s + start), maxlen);
	ptr[maxlen] = '\0';
	return (ptr);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, const char *src)
{
	ft_strcpy((dest + ft_strlen(dest)), src);
	return (dest);
}

static char	*ft_rejoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s2) + ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ptr)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	free(s1);
	s1 = NULL;
	return (ptr);
}

static ssize_t	get_return(char **line, char **saved, int c)
{
	char	*temp;

	*line = ft_substr(*saved, 0, ft_strclen(*saved, c));
	if (ft_strchr(*saved, c))
	{
		temp = *saved;
		*saved = ft_strdup(ft_strchr(*saved, c) + 1);
		free(temp);
		return (1);
	}
	ft_strdel(saved);
	return (0);
}

ssize_t	init(char **line,char **saved, size_t n, int fd)
{
	if (fd < 0 || !line)
		return (-1);
	if (!saved)
		*saved = ft_strdup("");
	*line = (char *)malloc(sizeof(char) * (n + 1));
	if (!*line)
		return (-1);
	return (0);
}

ssize_t	get_next_delim(char **line, size_t n, int c, int fd)
{
	static char	*saved;
	int			nbytes;

	if (init(line, &saved, n, fd))
		return (-1);
	nbytes = read(fd, *line, n);
	while (nbytes > 0)
	{
		(*line)[nbytes] = '\0';
		saved = ft_rejoin(saved, *line);
		if (ft_strchr(*line, c))
			break ;
		nbytes = read(fd, *line, n);
	}
	ft_strdel(line);
	if (nbytes < 0)
	{
		ft_strdel(&saved);
		return (-1);
	}
	return (get_return(line, &saved, c));
}
