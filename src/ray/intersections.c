/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:05 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:51:06 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_intersections	intersections(t_intersection values[], unsigned int count)
{
	t_intersection	*new_array;
	unsigned int	i;

	if (!values || !count)
		return ((t_intersections){NULL, 0});
	new_array = ft_calloc(count, sizeof(t_intersection));
	if (!new_array)
		exit(42);
	i = 0;
	while (i < count)
	{
		new_array[i] = values[i];
		i++;
	}
	return (
		(t_intersections){
			.array = sort_intersections(new_array, count),
			.count = count,
		}
	);
}
