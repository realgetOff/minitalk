/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:03:01 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 21:10:45 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

t_server	g_server;

char	get_bit(unsigned char *buffer)
{
	int	i;
	int	j;
	int	power;
	int	number;

	i = 0;
	j = 0;
	power = 1;
	number = 0;
	while (buffer[j])
		j++;
	j--;
	while (i < 8)
	{
		if (buffer[j] == '1')
			number += power;
		power *= 2;
		j--;
		i++;
	}
	return ((unsigned char)number);
}

void	decode_and_print(void)
{
	char	c;

	c = get_bit((unsigned char *)g_server.bits);
	if (c == '\0')
	{
		if (g_server.string_i >= g_server.allocated_size)
			expand_server_string();
		g_server.string[g_server.string_i] = '\0';
		ft_printf("\e[1;97m⤷ \e[m%s\n", g_server.string);
		kill(g_server.client_pid, SIGUSR2);
		free(g_server.string);
		init_server_string();
	}
	else
	{
		if (g_server.string_i + 1 >= g_server.allocated_size)
			expand_server_string();
		g_server.string[g_server.string_i] = c;
		g_server.string_i++;
	}
	ft_memset(g_server.bits, 0, 9);
	g_server.number = 0;
	if (g_server.client_pid > 0)
		kill(g_server.client_pid, SIGUSR1);
}

void	receive_bits(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server.number == 0)
		g_server.client_pid = info->si_pid;
	if (g_server.number < 8)
	{
		if (signum == SIGUSR1)
			g_server.bits[g_server.number++] = '0';
		else if (signum == SIGUSR2)
			g_server.bits[g_server.number++] = '1';
	}
	if (g_server.number == 8)
		decode_and_print();
}

int	main(void)
{
	struct sigaction	sa;

	g_server.string_i = 0;
	ft_bzero(&g_server, sizeof(g_server));
	init_server_string();
	g_server.server_pid = getpid();
	ft_printf("\e[1;1H\e[2J");
	ft_printf("\e[1;91m╔════•●•════╗\e[m\n");
	ft_printf("\e[1;93m   minitalk  \e[m\n");
	ft_printf("\e[1;91m╚════•●•════╝\e[m\n");
	ft_printf("\e[0;97m⫘⫘⫘⫘⫘⫘ \n[server] PID : \e[3;97m%d\n\e[m",
		g_server.server_pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_bits;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
