/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:50:45 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/10 00:30:21 by psitkin          ###   ########.fr       */
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

int main(int argc, char **argv)
{
	pid_t	sv_pid;

	int	i;
	
	i = 0;
	
	if (argc == 3)
	{
		sv_pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_char(sv_pid, argv[2][1]);
			i++;
		}
	}
	else
		exit(1);
	return(0);
}