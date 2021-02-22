/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:46:36 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/20 15:02:00 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_diglen(long int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

static char		*ft_revitoa(char *str, long int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		str[i] = '-';
		i++;
		num = (num * (-1));
	}
	else if (num == 0)
	{
		str[i] = '0';
		i++;
	}
	while (num)
	{
		str[i] = '0' + (num % 10);
		i++;
		num = (num / 10);
	}
	str[i] = '\0';
	return (str);
}

static void		ft_swapchr(char *a, char *b)
{
	char x;

	x = a[0];
	a[0] = b[0];
	b[0] = x;
}

static void		ft_strrev(char *str)
{
	int i;
	int j;

	j = ft_strlen(str) - 1;
	i = 0;
	while (i < j)
	{
		ft_swapchr(&str[i], &str[j]);
		i++;
		j--;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_diglen(n) + 1));
	if (!str)
		return (0);
	if (n <= 0)
		i++;
	ft_revitoa(str, n);
	if (i)
	{
		ft_strrev(str + i);
		return (str);
	}
	ft_strrev(str);
	return (str);
}
