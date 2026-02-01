/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:32:37 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 15:07:36 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_intersection	*sort_intersections(t_intersection val[], size_t len)
{
	t_intersection	temp;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (val[j].t < val[i].t)
			{
				temp = val[i];
				val[i] = val[j];
				val[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (val);
}
