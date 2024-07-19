/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:08:05 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/19 18:33:39 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_dec(long nbr, t_printf_list *ret)
{
	if (nbr < 0)
	{
		print_char('-', ret);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		print_dec(nbr / 10, ret);
		nbr = nbr % 10;
	}
	print_char(nbr + '0', ret);
}
