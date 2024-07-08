/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:51:07 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/19 19:30:00 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_nb(const char *str, size_t nb, int sign)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (nb > SIZE_MAX / 10)
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
		nb = nb * 10;
		if (nb > SIZE_MAX - (str[i] - 48))
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	size_t		nb;
	int			sign;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = sign * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = convert_nb(str + i, nb, sign);
	return ((int)nb * sign);
}
