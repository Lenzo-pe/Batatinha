/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:25:38 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/09 02:28:26 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int chr, size_t num)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (num--)
	{
		str1[i] = str2[i];
		if (str1[i] == (unsigned char)chr)
			return ((str1 + (i + 1)));
		i++;
	}
	return (0);
}
