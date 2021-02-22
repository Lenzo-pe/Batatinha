/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:10:50 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/16 03:14:52 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	char	*lastchr;

	lastchr = 0;
	while (*str)
	{
		if (*str == chr)
			lastchr = (char *)str;
		str++;
	}
	if (chr == 0)
		return ((char *)str);
	return (lastchr);
}
