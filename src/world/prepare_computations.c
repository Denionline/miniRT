/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:33 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:40:02 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_computations	prepare_computations(t_intersection inter, t_ray r)
{
	t_computations	comps;

	comps = (t_computations){};
	comps.t = inter.t;
	comps.object = inter.object;
	comps.point = position(r, comps.t);
	comps.eyev = negate_tuple(r.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = TRUE;
		comps.normalv = negate_tuple(comps.normalv);
	}
	else
		comps.inside = FALSE;
	comps.over_point = sum_tuples(
			comps.point,
			multiply_tuple(comps.normalv, NARUTO)
			);
	return (comps);
}
