/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:41:11 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/14 21:19:18 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char *str, char sep)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
			cnt++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (cnt);
}

static size_t	ft_getlenword(char *s, char c)
{
	size_t	length;

	length = 0;
	if (!ft_strchr((char *)s, c))
		length = ft_strlen((char *)s);
	else
		length = (size_t)(ft_strchr((char *)s, c) - s);
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

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	lword;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_countwords((char *)s, c);
	strs = (char **)malloc((count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	lword = 0;
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		lword = ft_getlenword((char *)s, c);
		if (*s)
			strs[i++] = ft_substr((char *)s, 0, lword);
		s += lword;
	}
	strs[i] = NULL;
	return (ft_checkstrs(strs, count));
}
