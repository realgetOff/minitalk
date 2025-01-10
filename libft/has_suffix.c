/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:44:01 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/06 08:46:13 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	has_suffix(const char *filename, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (filename[i])
		i++;
	while (str[j])
		j++;
	if (j > i)
		return (0);
	while (str[j - 1] == filename[i - 1] && j > 0)
	{
		i--;
		j--;
	}
	if (j == 0)
		return (0);
	return (1);
}
