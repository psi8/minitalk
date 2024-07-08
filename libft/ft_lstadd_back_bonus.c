/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:32:54 by psitkin           #+#    #+#             */
/*   Updated: 2023/11/19 15:04:03 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastlast;

	lastlast = *lst;
	if (!lastlast)
	{
		*lst = new;
		return ;
	}
	lastlast = ft_lstlast(lastlast);
	lastlast -> next = new;
}
