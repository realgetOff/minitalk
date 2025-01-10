/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:43:59 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/06 18:50:47 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_bits(char c, unsigned char bits[8])
{
	int				i;
	unsigned char	mask;

	i = 0;
	mask = 1 << 7;
	while (i < 8)
	{
		if (c & mask)
			bits[i] = 1;
		else
			bits[i] = 0;
		mask >>= 1;
		i++;
	}
}
