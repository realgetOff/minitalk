/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:13:30 by mforest-          #+#    #+#             */
/*   Updated: 2024/11/30 23:22:46 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	has_prefix(const char *filename, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[j] && filename[i]) && str[j] == filename[i])
	{
		j++;
		i++;
	}
	if (str[j] == '\0')
		return (0);
	return (1);
}
