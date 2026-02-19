/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:40:19 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/12 11:18:34 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(long int nbr)
{
	size_t	i;

	i = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nlong;
	size_t		size;
	size_t		neg;
	char		*str;

	nlong = n;
	neg = nlong < 0;
	if (nlong < 0)
		nlong *= -1;
	size = ft_getsize(nlong) + neg;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, '-', size);
	str[size] = '\0';
	while (size > neg)
	{
		str[(size--) - 1] = (char)(nlong % 10 + '0');
		nlong /= 10;
	}
	return (str);
}
