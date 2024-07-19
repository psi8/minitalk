/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:56:11 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/19 18:33:42 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, t_printf_list *ret)
{
	if (ret->error == -1)
		return ;
	if (write(1, &c, 1) < 0)
		ret->error = -1;
	else
		ret->length += 1;
}
