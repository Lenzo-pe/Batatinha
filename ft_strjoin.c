/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:07:59 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/19 04:32:30 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2);
	total_len = s2_len + s1_len;
	ptr = (char *)malloc(sizeof(char) * (total_len));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, s1_len);
	ft_strlcat(ptr, s2, total_len);
	return (ptr);
}
