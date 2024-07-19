/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:11:16 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/18 21:16:03 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*add_to_string(char const *s1, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free ((void *)(s1));
	return (tab);
}

void	print_and_free(char **string)
{
	ft_printf("%s\n", *string);
	free (*string);
	*string = NULL;
}

void	signal_handler(int sig)
{
	static int	bit_pos = 0;
	static int	char_val = 0;
	static int	len = 0;
	static char	*string;

	if (!string)
		string = ft_strdup("");
	if (sig == SIGUSR2)
		char_val = ((char_val << 1) | 1);
	else if (sig == SIGUSR1)
		char_val = (char_val << 1);
	bit_pos++;
	if (bit_pos == 8)
	{
		string = add_to_string(string, char_val);
		if (char_val == '\0')
			print_and_free(&string);
		bit_pos = 0;
		char_val = 0;
		len += 1;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}