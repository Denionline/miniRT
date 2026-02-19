/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:44:36 by dximenes          #+#    #+#             */
/*   Updated: 2025/11/22 10:44:31 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_strmatch(char *s1, char *s2)
{
	int	ls1;
	int	ls2;
	int	size;

	if (!s1 && !s2)
		return (TRUE);
	if (!s1 || !s2)
		return (FALSE);
	if (!(*s1) && !(*s2))
		return (TRUE);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	size = ls1;
	if (ls1 < ls2)
		size = ls2;
	return (!ft_strncmp(s1, s2, size));
}
