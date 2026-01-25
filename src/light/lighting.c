#include "head.h"

t_tuple	lighting(t_material material, t_light l, t_tuple p,	t_phong_vec phong)
{
	t_tuple			vetor_light;
	float			AB_cos;
	t_phong_colors	colors;

	if (material.pattern.has_pattern)
		material.color = stripe_at(material.pattern, p);
	colors.effective = multiply_tuple_tuple(material.color, l.intensity);
	vetor_light = normalize(subtract_tuples(l.position, p));
	colors.ambient = multiply_tuple(colors.effective, material.ambient);
	AB_cos = dot(vetor_light, phong.normalv);
	if (AB_cos < 0 || phong.in_shadow)
	{
		colors.difuse = color_float(0, 0, 0);
		colors.specular = color_float(0, 0, 0);
	}
	else
	{
		colors.difuse = multiply_tuple(colors.effective, material.difuse * AB_cos);
		AB_cos = dot(reflect(negate_tuple(vetor_light), \
phong.normalv), phong.eyev);
		if (AB_cos <= 0)
			colors.specular = color_float(0, 0, 0);
		else
			colors.specular = multiply_tuple(l.intensity, material.specular * pow(AB_cos, material.shininess));
	}
	return (sum_tuples(colors.ambient, sum_tuples(colors.difuse, colors.specular)));
}
