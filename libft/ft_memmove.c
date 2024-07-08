/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:28:38 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/19 19:55:23 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	if ((!src && !dst) && (len != 0))
		return (NULL);
	temp = dst;
	if (dst <= src)
		while (len--)
			*temp++ = *(char *) src++;
	else
	{
		temp += len;
		src += len;
		while (len--)
			*(--temp) = *(char *)(--src);
	}
	return (dst);
}
