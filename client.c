/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:50:45 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/11 00:04:51 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int	ft_send_len(int sv_pid, char *str)
{
	int	i;
	size_t	len;
	
	i = 0;
	len = ft_strlen(str);
	if (len >= MAX_LEN)
	{
		ft_printf("Too long message");
		return (0);
	}
	while (i < 32)
	{
		if ((len >> i) & 1)
			kill(sv_pid, SIGUSR2);
		else
			kill(sv_pid, SIGUSR1);
		usleep(100);
		i++;
	}
	return(1);
}


void	ft_send_str(int sv_pid, char *str)
{
	int	i;
	int	c;
	int j;
	
	j = 0;
	while (str[j])
	{
		c = str[j];
		i = 0;
		while(i < 8)
		{
			if ((c >> i) & 1)
				kill(sv_pid, SIGUSR2);
			else
				kill(sv_pid, SIGUSR1);
			usleep (100);
			i++;
		} 
		j++;
	}
}

int main(int argc, char **argv)
{
	pid_t	sv_pid;

	int	i;
	
	i = 0;
	
	if (argc == 3)
	{
		sv_pid = ft_atoi(argv[1]);
		if (sv_pid <= 0)
		{
			ft_putstr_fd("invalid PID: ", 2);
			ft_putstr_fd(argv[1], 2);
			exit(1);
		}
		if (!ft_send_str_len(sv_pid, argv[2]))
			exit (0);
		ft_send_str(sv_pid, argv[2]);
	}
	else
	{
		ft_printf("hello")
	}
	return(0);
}