/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:57:11 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/16 00:53:35 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*c_s1;
	char	*c_s2;

	c_s1 = (char *)s1;
	c_s2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (c_s1[i] != c_s2[i])
			return ((unsigned char)c_s1[i] - (unsigned char)c_s2[i]);
		i++;
	}
	return (0);
}
