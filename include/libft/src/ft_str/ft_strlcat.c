/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:11:15 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/13 11:57:10 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;
	char	*s_src;

	if (size == 0 && dst == NULL)
		return (0);
	s_src = (char *)src;
	ldst = 0;
	lsrc = ft_strlen(s_src);
	while (dst[ldst] && ldst < size)
		ldst++;
	if (ldst == size)
		return (lsrc + ldst);
	i = 0;
	while (s_src[i] && ((ldst + i) + 1) < size)
	{
		dst[ldst + i] = s_src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (lsrc + ldst);
}
