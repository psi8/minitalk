/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:44:03 by psitkin           #+#    #+#             */
/*   Updated: 2023/12/27 18:27:29 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(long nbr, int upper_case, t_list *ret)
{
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		print_hex(nbr / 16, upper_case, ret);
		nbr = nbr % 16;
	}
	if (upper_case)
		print_char(upper[nbr], ret);
	else
		print_char(lower[nbr], ret);
}
