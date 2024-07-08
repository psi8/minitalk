/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:09:16 by psitkin           #+#    #+#             */
/*   Updated: 2023/12/27 17:41:14 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct t_list
{
	int	length;
	int	error;
}		t_list;

int		ft_printf(const char *format, ...);
void	print_format(char spec, va_list ap, t_list *ret);
void	print_char(int c, t_list *ret);
void	print_str(char *str, t_list *ret);
void	print_dec(long nbr, t_list *ret);
void	print_hex(long nbr, int upper_case, t_list *ret);
void	print_ptr(unsigned long nbr, t_list *ret);

#endif