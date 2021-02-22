/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 23:55:29 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/20 14:38:50 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strclen(const char *str, const char chr)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != chr)
		i++;
	return (i);
}

static size_t	ft_strltok(const char *str, char chr)
{
	size_t	i;
	size_t	strn;

	i = 0;
	strn = 0;
	while (str[i])
	{
		if (str[i] != chr)
			strn++;
		while (str[i] != chr && str[i + 1])
			i++;
		i++;
	}
	return (strn);
}

static char		**ft_strnalloc(char **ptr, const char *s, char c, size_t num)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	while (num--)
	{
		while (s[i] == c && s[i])
			i++;
		s_len = ft_strclen((s + i), c);
		*ptr++ = ft_substr(s, i, s_len);
		i = s_len + i;
	}
	*ptr = 0;
	return (ptr);
}

char			**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	tokens_n;

	if (!s)
		return (0);
	tokens_n = ft_strltok(s, c);
	ptr = (char **)malloc(sizeof(char **) * (tokens_n + 1));
	if (!ptr)
		return (0);
	ft_strnalloc(ptr, s, c, (tokens_n));
	return (ptr);
}
