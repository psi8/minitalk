/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:11:16 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/10 00:57:50 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sigusr1_handler(int sig)
{
	if(sig == SIGUSR1)
	{
		ft_strcpy(g_sstr, g_cstr);
		printf("Recieved SIGUSR1\n");
		printf("recieved string: %s\n", g_sstr);
	}
}

void	sigusr2_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_strcpy(g_sstr, g_cstr);
		printf("Received SIGUSR2\n");
		printf("Received string: %s\n", g_sstr);
	}
}


int main()
{
	int	c;
	pid_t sv_pid;
	
	sv_pid = getgid();
	c = 0;
	ft_memset(g_sstr, 0, sizeof(g_sstr));
	printf("Server PID %d\n", sv_pid);
	signal(SIGUSR1, sigusr1_handler);
	kill(sv_pid,SIGUSR1);
	if (kill(sv_pid, SIGUSR1) == -1)
	{
		exit(1);
	}
	sleep(1);
	while (c < 1)
	{
		pause();
		c++;
	}
	return (0);
}