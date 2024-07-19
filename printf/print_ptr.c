/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:58:25 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/19 18:33:50 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(unsigned long nbr, t_printf_list *ret)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (nbr >= 16)
	{
		print_ptr(nbr / 16, ret);
		nbr = nbr % 16;
	}
	print_char(digits[nbr], ret);
}
