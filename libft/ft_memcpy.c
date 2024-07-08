/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:50:01 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/19 19:55:13 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	if (!src && !dst)
		return (NULL);
	x = 0;
	while (x < n)
	{
		d[x] = s[x];
		x++;
	}
	return (d);
}
