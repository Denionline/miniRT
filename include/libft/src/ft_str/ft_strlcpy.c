/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:51:39 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/09 18:57:57 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	lsrc;
	size_t	lcopy;
	char	*s_src;

	s_src = (char *)src;
	lsrc = ft_strlen(s_src);
	if (lsrc >= size)
		lcopy = size - 1;
	else
		lcopy = lsrc;
	if (size > 0)
	{
		ft_memcpy(dst, s_src, lcopy);
		dst[lcopy] = '\0';
	}
	return (lsrc);
}
