#include "get_next_line_bonus.h"

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

t_list	*lst_new(void *content, int fd)
{
	t_list *lst;

	lst = malloc(sizeof(t_list));
	lst->saved = content;
	lst->next = NULL;
	lst->index = fd;
	return (lst);
}

static void lst_init(t_list **lst, int fd)
{
	if (!*lst)
		*lst = lst_new(ft_strdup(""), fd);
	else if ((*lst)->index != fd)
		lst_init(&(*lst)->next, fd);
	else if (!(*lst)->saved)
		(*lst)->saved = ft_strdup("");
}

static ssize_t	init(char **line, t_list **lst, size_t n, int fd)
{
	if (fd < 0 || !line)
		return (-1);
	lst_init(lst, fd);
	*line = (char *)malloc(sizeof(char) * (n + 1));
	if (!*line)
		return (-1);
	return (0);
}

static void	ft_lstdel(t_list **lst)
{
	if (lst && *lst)
	{
		ft_strdel(&(*lst)->saved);
		free(*lst);
		*lst = NULL;
	}
}

static void	ft_lstdeljoin(t_list **lst, t_list *del)
{
	t_list	*ptr;

	ptr = *lst;
	if (ptr == del)
	{
		*lst = (*lst)->next;
		ft_lstdel(&del);
		return ;
	}
	while (ptr->next != del)
		ptr = ptr->next;
	ptr->next = ptr->next->next;
	ft_lstdel(&del);
}

static t_list	*lst_saved(t_list *lst, int fd)
{
	while (lst->index != fd)
		lst = lst->next;
	return (lst);
}

static ssize_t	get_return(char **line, t_list **lst, t_list **ptr, int c)
{
	char	*temp;

	*line = ft_substr((*ptr)->saved, 0, ft_strclen((*ptr)->saved, c));
	if (ft_strchr((*ptr)->saved, c))
	{
		temp = (*ptr)->saved;
		(*ptr)->saved = ft_strdup(ft_strchr((*ptr)->saved, c) + 1);
		free(temp);
		return (1);
	}
	ft_lstdeljoin(lst, *ptr);
	return (0);
}

static ssize_t	get_delim(char **line, char **saved, size_t n, int c, int fd)
{
	int			nbytes;

	nbytes = read(fd, *line, n);
	while (nbytes > 0)
	{
		(*line)[nbytes] = '\0';
		*saved = ft_rejoin(*saved, *line);
		if (ft_strchr(*line, c))
			break ;
		nbytes = read(fd, *line, n);
	}
	ft_strdel(line);
	if (nbytes < 0)
		return (-1);
	return (0);
}

ssize_t	get_next_delim(char **line, size_t n, int c, int fd)
{
	static t_list	*lst;
	t_list *ptr;

	if (init(line, &lst, n, fd))
		return (-1);
	ptr = lst_saved(lst, fd);
	if (get_delim(line, &ptr->saved, n, c, fd))
	{
		ft_strdel(&ptr->saved);
		return (-1);
	}
	return (get_return(line, &lst, &ptr, c));
}
