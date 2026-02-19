/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:41:09 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/14 21:17:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	ls;
	size_t	i;

	if (!s)
		return (ft_strdup(""));
	ls = ft_strlen((char *)s);
	str = (char *)malloc((ls + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
