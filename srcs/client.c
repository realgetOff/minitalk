/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:41:13 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 21:13:07 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

t_server	g_server;
int			g_ack_received = 0;

void	handle_receipt(int signum)
{
	(void)signum;
	ft_printf("\e[0;97m\n╰─•◈ The server successfully"
		" received the string. ◈•─╯ \e[m\n");
}

void	handle_ack(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

int	sent_bits(pid_t pid, unsigned char *bits)
{
	int	j;

	g_ack_received = 0;
	j = 0;
	while (j != 8)
	{
		if (bits[j] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		j++;
	}
	while (!g_ack_received)
		usleep(50);
	return (0);
}

int	encrypt(pid_t pid, char *str)
{
	int				i;
	unsigned char	bits[9];
	unsigned char	null_bits[8];

	i = 0;
	ft_bzero(null_bits, 8);
	ft_bzero(bits, 9);
	while (str[i])
	{
		ft_putnbr_bits(str[i], bits);
		sent_bits(pid, bits);
		i++;
	}
	sent_bits(pid, null_bits);
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	g_server.client_pid = getpid();
	ft_printf("\e[1;1H\e[2J");
	ft_printf("\e[1;91m╔════•●•════╗\e[m\n");
	ft_printf("\e[1;96m   minitalk  \e[m\n");
	ft_printf("\e[1;91m╚════•●•════╝\e[m\n");
	ft_printf("\e[0;97m⫘⫘⫘⫘⫘⫘ \n[client] PID : \e[3;97m%d\n\e[m",
		g_server.client_pid);
	if (ac == 3)
	{
		pid = (pid_t)ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_perror("Invalid PID");
			return (EXIT_FAILURE);
		}
		signal(SIGUSR1, handle_ack);
		signal(SIGUSR2, handle_receipt);
		encrypt(pid, av[2]);
	}
	else
		ft_perror("Usage: ./client <PID_Server> <Message>");
	return (EXIT_SUCCESS);
}
