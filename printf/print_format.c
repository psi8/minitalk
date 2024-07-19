/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:33:40 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/19 18:35:33 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(char specifier, va_list ap, t_printf_list *ret)
{
	if (specifier == 'c')
		print_char(va_arg(ap, int), ret);
	else if (specifier == 's')
		print_str(va_arg(ap, char *), ret);
	else if (specifier == 'd' || specifier == 'i')
		print_dec((long)(va_arg(ap, int)), ret);
	else if (specifier == 'u')
		print_dec((long)(va_arg(ap, unsigned int)), ret);
	else if (specifier == 'x')
		print_hex((long)(va_arg(ap, unsigned int)), 0, ret);
	else if (specifier == 'X')
		print_hex((long)(va_arg(ap, unsigned int)), 1, ret);
	else if (specifier == 'p')
	{
		print_str("0x", ret);
		print_ptr((unsigned long)va_arg(ap, void *), ret);
	}
	else
		print_char(specifier, ret);
}
