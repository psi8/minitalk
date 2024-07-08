/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:59:47 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/16 00:54:37 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	long	l;

	l = ft_strlen(src) + 1;
	dst = malloc(l);
	if (!dst)
		return ((char *) 0);
	ft_strlcpy(dst, src, l);
	return (dst);
}
