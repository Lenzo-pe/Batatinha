/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:20:26 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/20 14:19:49 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v' ||
	c == '\r' || c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *nptr)
{
	int		holder;
	int		sign;

	sign = 1;
	holder = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		holder = (holder * 10) + (*nptr++ - '0');
	return (holder * sign);
}
