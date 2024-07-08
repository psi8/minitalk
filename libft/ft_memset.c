/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:09:06 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/19 19:55:32 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *) ptr;
	while (len > 0)
	{
		*str = (unsigned char)value;
		str++;
		len--;
	}
	return (ptr);
}
