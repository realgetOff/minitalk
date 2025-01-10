/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:09:42 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/06 17:37:37 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_putnbr_base(int nbr, char *base)
{
	char	*result;
	int		base_len;
	int		temp;
	int		size;

	base_len = 2;
	temp = nbr;
	size = 0;
	while (temp > 0)
	{
		temp /= base_len;
		size++;
	}
	if (size == 0)
		size = 1;
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (size > 0)
	{
		result[--size] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (result);
}
