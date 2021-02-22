/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:01:41 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/19 01:37:45 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int chr, size_t num)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)ptr;
	while (num--)
	{
		if (str[i] == (unsigned char)chr)
			return ((str + i));
		i++;
	}
	return (0);
}
