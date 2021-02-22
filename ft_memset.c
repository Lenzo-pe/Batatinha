/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:23:54 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/20 10:29:27 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t num)
{
	unsigned char	*str;
	unsigned char	value;

	str = ptr;
	value = (unsigned char)c;
	while (num--)
	{
		*str = value;
		str++;
	}
	return (ptr);
}
