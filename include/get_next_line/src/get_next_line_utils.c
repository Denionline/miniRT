/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:37:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 10:36:40 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_linelen(char *prev, char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (prev && prev[i])
		i++;
	j = 0;
	while (buffer && buffer[j] && buffer[j - 1] != '\n')
		j++;
	return (i + j);
}

char	*ft_clear(char *buff)
{
	free(buff);
	return (NULL);
}

int	ft_changebuffer(char *buffer)
{
	int	i;
	int	j;
	int	bk;

	bk = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (bk)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			bk = 1;
		buffer[i++] = '\0';
	}
	while (j < i)
		buffer[j++] = '\0';
	return (bk);
}

char	*ft_linejoin(char *prev, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	line = malloc(ft_linelen(prev, buffer) + 1);
	if (!line)
		return (ft_clear(prev));
	i = 0;
	while (prev && prev[i])
	{
		line[i] = prev[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j] && buffer[j - 1] != '\n')
	{
		line[i + j] = buffer[j];
		j++;
	}
	line[i + j] = '\0';
	free(prev);
	return (line);
}
