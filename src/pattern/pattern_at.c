/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:32:55 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 15:04:27 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static t_tuple	gradient_color(t_pattern pat, t_tuple p)
{
	t_tuple	distance;
	float	fraction;

	distance = subtract_tuples(pat.b, pat.a);
	fraction = (p.x - floor(p.x)) * 1.0f;
	if (fraction < 0)
		fraction = 0;
	if (fraction > 1)
		fraction = 1;
	return (sum_tuples(pat.a, multiply_tuple(distance, fraction)));
}

static t_tuple	checkboard_color(t_pattern pat, t_tuple p)
{
	float	p1;
	float	p2;

	p1 = floor(p.x * pat.width);
	p2 = floor(p.y * pat.height);
	if (fmod(p1 + p2, 2) == 0)
		return (pat.a);
	return (pat.b);
}

t_tuple	pattern_at(t_pattern pat, t_tuple p)
{
	float	dist;

	if (pat.type_p == RING)
	{
		dist = fmod(floor(sqrt(p.x * p.x + p.y * p.y) * 6), 2);
		if (dist == 0)
			return (pat.a);
		return (pat.b);
	}
	if (pat.type_p == STRIP)
	{
		if ((int)floorf(p.x * 1) % 2 == 0)
			return (pat.a);
		return (pat.b);
	}
	if (pat.type_p == GRADIENT)
		return (gradient_color(pat, converter_map(p, pat.tpye_obj)));
	if (pat.type_p == CHECKBOARD)
		return (checkboard_color(pat, converter_map(p, pat.tpye_obj)));
	return (color_float(0, 0, 0));
}

t_tuple	pattern_at_obj(t_pattern p, t_object obj, t_tuple pos)
{
	t_tuple	obj_point;

	obj_point = multiply_matrix_tuple((obj.transform), pos);
	return(pattern_at(p, obj_point));
}
