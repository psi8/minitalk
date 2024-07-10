/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:50:45 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/10 17:31:40 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>


void	send_bit(int sv_pid, int bit)
{
	if (bit == 1)
		kill(sv_pid, SIGUSR1);
	else
		kill(sv_pid, SIGUSR2);
	usleep(42);
}

void	send_char(int sv_pid, char ch)
{
	int	i;
	int	bit;
	
	i = 8;
	while (i > 0)
	{
		bit = (ch >> i) & 1;
		send_bit(sv_pid, bit);
		i--;
	}
	
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
			kill(sv_pid, SIGUSR1 + (1 & (c >> i)));
			usleep (50);
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
		ft_printf("")
	}
	return(0);
}