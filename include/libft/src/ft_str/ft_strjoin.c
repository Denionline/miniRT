/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:21:44 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/14 22:16:00 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	ls1;
	char	*str;

	if (!s1 || !s2)
		return (ft_strdup(""));
	ls1 = ft_strlen((char *)s1);
	str = (char *)malloc((ls1 + ft_strlen((char *)s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ls1 + i] = s2[i];
		i++;
	}
	str[ls1 + i] = '\0';
	return (str);
}
