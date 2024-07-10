/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:37:58 by psitkin           #+#    #+#             */
/*   Updated: 2024/07/10 23:43:20 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define MAX_LEN 4294967295
# define INT_MAX 2147483648


#define _POSIX_C_SOURCE 200809L  // do we need this??

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void	ft_send_len(int sv_pid, char *str);
void	ft_send_str(int sv_pid, char *str);
void	ft_get_string(int sig, siginfo_t *info, void *context);
int	ft_get_mes(char *msg, int sig, int len);


#endif