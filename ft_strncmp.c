/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:30:54 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/10 22:31:22 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned int	i;

	i = 0;
	if (!num)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && --num)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
