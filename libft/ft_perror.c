/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:12:49 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/09 01:06:08 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror(char *string)
{
	ft_printf("\e[1;1H\e[2J"
		"\e[1;31m[ERROR]\e[m\n"
		"\e[3;31m%s.\e[m\n", string);
}