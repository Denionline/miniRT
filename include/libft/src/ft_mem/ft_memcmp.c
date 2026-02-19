/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:36:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/09 21:41:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_s1;
	unsigned char	*s_s2;
	size_t			i;

	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s_s1[i] != s_s2[i])
			return (s_s1[i] - s_s2[i]);
		i++;
	}
	return (0);
}
