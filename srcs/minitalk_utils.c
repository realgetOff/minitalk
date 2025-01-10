/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:37:17 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 21:14:07 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	init_server_string(void)
{
	g_server.string_i = 0;
	g_server.allocated_size = 128;
	g_server.string = malloc(g_server.allocated_size);
	if (!g_server.string)
	{
		ft_perror("Allocation failed.");
		exit(EXIT_FAILURE);
	}
	ft_memset(g_server.string, 0, g_server.allocated_size);
}

void	expand_server_string(void)
{
	size_t	new_size;
	char	*new_ptr;

	new_size = g_server.allocated_size * 2;
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		ft_perror("Expend allocation failed.");
		free(g_server.string);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(new_ptr, g_server.string, g_server.string_i);
	ft_memset(new_ptr + g_server.string_i, 0, new_size - g_server.string_i);
	free(g_server.string);
	g_server.string = new_ptr;
	g_server.allocated_size = new_size;
}
