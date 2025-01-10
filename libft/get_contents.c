/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_contents.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:58:36 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/01 03:44:49 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*concat(char *s1, char *s2, int len)
{
	int		s1_len;
	int		len_max;
	char	*new;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (strdup(s2));
	s1_len = strlen(s1);
	len_max = len + 1 + s1_len;
	new = malloc(sizeof(char) * len_max + 1);
	if (!new)
		return (NULL);
	memcpy(new, s1, s1_len);
	memcpy(new + s1_len, s2, len + 1);
	new [s1_len + len] = '\0';
	return (new);
}

char	*get_contents_from_fd(int fd)
{
	char	buffer[8193];
	char	*result;
	int		len;
	char	*tmp;

	result = NULL;
	while (true)
	{
		len = read(fd, buffer, 8192);
		if (len <= 0)
			break ;
		buffer[len] = 0;
		tmp = result;
		result = concat(result, buffer, len);
		if (result == NULL)
			return (NULL);
		free(tmp);
	}
	return (result);
}

char	*get_contents(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	return (get_contents_from_fd(fd));
}
