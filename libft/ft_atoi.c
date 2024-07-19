/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:51:07 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/19 17:25:25 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\12');
}

int	ft_atoi(const char *str)
{
	int			i;
	int long	rtn;
	int			sign;

	i = 0;
	rtn = 0;
	sign = 1;
	while (str[i] && (ft_isspace(str[i])))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		rtn = 10 * rtn + str[i++] - '0';
		if (rtn < 0 && sign < 0)
			return (0);
		else if (rtn < 0 && sign > 0)
			return (-1);
	}
	return (rtn * sign);
}