/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:06:22 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/19 18:28:05 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf_list		ret;
	int			i;

	ret.length = 0;
	ret.error = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			print_format(format[i + 1], ap, &ret);
			i++;
		}
		else
			print_char(format[i], &ret);
		i++;
	}
	va_end(ap);
	if (ret.error == -1)
		return (-1);
	return (ret.length);
}
