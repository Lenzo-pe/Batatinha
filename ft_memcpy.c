/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:49:38 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/20 11:08:35 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!dest && !src)
		return (dest);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (num--)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	return (dest);
}
