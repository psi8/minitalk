/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:11:16 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/10 23:36:51 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_get_mes(char *msg, int sig, int len)
{
	static int	c;
	static int	i;
	static int	bit_pos;

	c = 0;
	i = 0;
	bit_pos = 0;
	
	if (sig == SIGUSR1)
		c = c | (0 << bit_pos);
	else if (sig == SIGUSR2)
		c |= (1 << bit_pos);
	
	bit_pos++;
	
	if(bit_pos == 8)
	{
		msg[i] = c;
		i++;
		c = 0;
		bit_pos = 0;
	
		if(i == len)
		{
			i = 0;
			return(1);
		}
	}
	else
		return(0);
}

void	ft_get_string(int sig, siginfo_t *info, void *context)
{
	static char	*msg;
	static size_t	len;
	static int	bit_pos;

	msg = NULL;
	len = 0;
	bit_pos = 0;
	(void)context;
	
	if(len)
	{
		if (sig == SIGUSR1)
			len |= (0 << bit_pos);
		else if (sig == SIGUSR2)
			len |= (1 << bit_pos);
		bit_pos++;

		if (bit_pos == 32)
		{
			msg = malloc(len + 1);
			if (msg == NULL)
			{
				write(2, "Memory allocation failed\n", 25);
				exit(1);
			}
			bit_pos = 0;
		}
	}
	else
	{
		if (ft_get_mes(msg, sig, len))
		{
			msg[len] = '\0';
			write(1, msg, len);
			write(1, "\n", 1);
			free(msg);
			msg = NULL;
			len = 0;
		}
	}
}


int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_get_string;
	ft_printf("server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
	{
		pause();
	}
	return(0);
}