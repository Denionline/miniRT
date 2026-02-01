/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:34 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:15:40 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	is_shadowed(t_world w, t_tuple p)
{
	t_tuple			vector_d;
	t_ray			r;
	float			distance;
	t_intersection	rit;
	t_intersections	inters;
 
	vector_d = subtract_tuples(w.light.position, p);
	distance = magnitude(vector_d);
	r = ray(p, normalize(vector_d));
	inters = intersect_world(w, r);
	rit = hit(inters);
	free(inters.array);
	if (rit.object && rit.t < distance)
		return (TRUE);
	return (FALSE);
}
