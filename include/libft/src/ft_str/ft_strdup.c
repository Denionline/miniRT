/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:11:37 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/09 21:45:53 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*array;
	size_t	len;

	len = ft_strlen(s) + 1;
	array = (char *)malloc(len);
	if (array == NULL)
		return (NULL);
	ft_memcpy(array, s, len);
	return (array);
}
