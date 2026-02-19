/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:25:40 by dximenes          #+#    #+#             */
/*   Updated: 2025/09/11 09:36:02 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delimitador(char c, char *delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		if (delim[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_countwords(char *str, char *sep)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (is_delimitador(str[i], sep))
			i++;
		if (str[i] && !is_delimitador(str[i], sep))
			cnt++;
		while (str[i] && !is_delimitador(str[i], sep))
			i++;
	}
	return (cnt);
}

static size_t	ft_getlenword(char *s, char *c)
{
	size_t	length;

	length = 0;
	while (s[length])
	{
		if (is_delimitador(s[length], c))
			break ;
		length++;
	}
	return (length);
}

static char	**ft_checkstrs(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && strs[i] != NULL)
		i++;
	if (i == n)
		return (strs);
	i = 0;
	while (i < n)
	{
		if (strs[i] != NULL)
			free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_strtok(char const *s, char *delim)
{
	char	**strs;
	size_t	lword;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_countwords((char *)s, delim);
	strs = (char **)malloc((count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	lword = 0;
	i = 0;
	while (*s)
	{
		while (*s && is_delimitador(*s, delim))
			s++;
		lword = ft_getlenword((char *)s, delim);
		if (*s)
			strs[i++] = ft_substr((char *)s, 0, lword);
		s += lword;
	}
	strs[i] = NULL;
	return (ft_checkstrs(strs, count));
}
