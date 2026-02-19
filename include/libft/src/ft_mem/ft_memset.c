/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:49:15 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/12 11:11:04 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_s;
	size_t			i;

	s_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
