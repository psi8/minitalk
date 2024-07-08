/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:23:45 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/17 00:51:42 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	start = 0;
	end = 0;
	if (!set || !s1)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	if (start == (size_t)ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end)
		end--;
	ptr = ft_substr(s1, start, (end - start + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}
