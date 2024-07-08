/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:56:32 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/16 00:56:50 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*joinstr;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joinstr = malloc(s1_len + s2_len + 1);
	if (!joinstr)
		return (0);
	ft_memmove(joinstr, s1, s1_len);
	ft_memmove(joinstr + s1_len, s2, s2_len);
	joinstr[s1_len + s2_len] = 0;
	return (joinstr);
}
