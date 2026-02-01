/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:31:00 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 15:35:45 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	set_color_empty(t_tuple *t1, t_tuple *t2)
{
	*t1 = color_float(0, 0, 0);
	*t2 = color_float(0, 0, 0);
}

t_tuple	lighting(t_material m, t_light l, t_tuple p, t_phong_vec pv)
{
	t_tuple			vetor_light;
	float			ab_cos;
	t_phong_colors	colors;

	if (m.pattern.has_pattern)
		m.color = pattern_at_obj(m.pattern, *pv.object, p);
	colors.effective = multiply_tuple_tuple(m.color, l.intensity);
	vetor_light = normalize(subtract_tuples(l.position, p));
	colors.ambient = multiply_tuple(colors.effective, m.ambient);
	ab_cos = dot(vetor_light, pv.normalv);
	if (ab_cos < 0 || pv.in_shadow)
		set_color_empty(&colors.difuse, &colors.specular);
	else
	{
		colors.difuse = multiply_tuple(colors.effective, m.difuse * ab_cos);
		ab_cos = dot(reflect(negate_tuple(vetor_light), pv.normalv), pv.eyev);
		if (ab_cos <= 0)
			colors.specular = color_float(0, 0, 0);
		else
			colors.specular = multiply_tuple(
					l.intensity,
					m.specular * pow(ab_cos, m.shininess));
	}
	return (sum_tuples(colors.ambient,
			sum_tuples(colors.difuse, colors.specular)));
}
