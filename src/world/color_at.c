/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:37 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:15:39 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	color_at(t_world w, t_ray r)
{
	t_intersections	inters;
	t_intersection	h;
	t_computations	comps;
	t_tuple			result;

	inters = intersect_world(w, r);
	h = hit(inters);
	if (!h.object)
	{
		free(inters.array);
		return (color_float(0, 0, 0));
	}
	comps = prepare_computations(h, r);
	free(inters.array);
	result = shade_hit(w, comps);
	return (result);
}
