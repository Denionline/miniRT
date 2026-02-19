/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:37:29 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/14 22:16:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ls1;
	char	*end;

	if (!s1 || !set)
		return (ft_strdup(""));
	ls1 = ft_strlen((char *)s1);
	end = (char *) s1 + ls1 - (*s1 != '\0');
	while (ft_strchr((char *)set, *s1))
		s1++;
	if (s1 >= end)
		return (ft_strdup(""));
	while (ft_strchr((char *)set, *end))
		end--;
	return (ft_substr((char *)s1, 0, (size_t)(end - s1 + 1)));
}
