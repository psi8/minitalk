/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:56:11 by psitkin           #+#    #+#             */
/*   Updated: 2023/12/27 17:58:41 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, t_list *ret)
{
	if (ret->error == -1)
		return ;
	if (write(1, &c, 1) < 0)
		ret->error = -1;
	else
		ret->length += 1;
}
