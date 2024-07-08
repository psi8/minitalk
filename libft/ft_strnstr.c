/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:20:55 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/19 19:56:44 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!haystack && len == 0)
		return ((char *)needle);
	if (!*needle)
		return ((char *)(haystack));
	while (*haystack && len > 0)
	{
		i = 0;
		while (needle[i] == haystack[i] && needle[i] && i < len)
		{
			i++;
			if (!needle[i])
				return ((char *)(haystack));
		}
		haystack++;
		len--;
	}
	return (NULL);
}
