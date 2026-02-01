/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:37 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:33:38 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	color_at(t_world w, t_ray r)
{
	t_intersections	inters;
	t_intersection	h;
	t_computations	comps;

	inters = intersect_world(w, r);
	h = hit(inters);
	//free_here
	if (!h.object)
		return (color_float(0, 0, 0));
	comps = prepare_computations(h, r);
	return (shade_hit(w, comps));
}
