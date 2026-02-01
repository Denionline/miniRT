/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:32 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:33:33 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	shade_hit(t_world w, t_computations comps)
{
	t_phong_vec	pv;

	pv.eyev = comps.eyev;
	pv.normalv = comps.normalv;
	pv.in_shadow = is_shadowed(w, comps.over_point);
	return (lighting(comps.object->material, w.light, comps.over_point, pv, *comps.object));
}
