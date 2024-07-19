/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:50:45 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/19 17:08:09 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	error_and_exit(int err)
{
	if(err == 1)
		ft_printf("Error : No server id\n");
	if(err == 2)
		ft_printf("Error: No string provided\n");
	if(err == 3)
		ft_printf("Error: Incorrect PID\n");
	if(err == 4)
		ft_printf("Error: No message recieved\n");
	if(err == 5)
		ft_printf("Error: Use format: ./client <PID_SERVER> <\"STRING\">\n");
	if(err == 6)
		ft_printf("Kill fail \n")
	exit(0);
}


void	send_sig(int pid, char *string)
{
	int	string_pos;
	int	bit_pos;

	string_pos = 0;
	while (string[string_pos])
	{
		bit_pos = 0;
		while (bit_pos < 8)
		{
			if (((unsigned char)(string[string_pos] >> (7 - bit_pos)) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			bit_pos++;
		}
		string_pos++;
	}
	bit_pos = 0;
	while (bit_pos < 8)
	{
		kill(pid, SIGUSR1);
		usleep(200);
		bit_pos++;
	}
}

int	main(int argc, char **argv)
{
	char				*string;
	int					server_id;

	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		if (!server_id)
			error_and_exit(1);
		if (kill(server_id, 0) == -1)
			error_and_exit(3);
		string = argv[2];
		if (string[0] == 0)
			error_and_exit(2);
		send_sig(server_id, string);
	}
	else
		error_and_exit(5);
	return (EXIT_SUCCESS);
}