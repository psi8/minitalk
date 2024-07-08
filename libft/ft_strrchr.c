/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:07 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/19 20:33:32 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)(str + len));
	while (len > 0)
	{
		len--;
		if (str[len] == (char)c)
			return ((char *)(str + len));
	}
	return (NULL);
}
