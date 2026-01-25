#ifndef LIGHT_H
# define LIGHT_H

#include "obj.h"
#include "math_head.h"

typedef struct s_light
{
	t_tuple	position;
	t_tuple	intensity;
}	t_light;

typedef	struct s_phong_vec
{
	t_tuple	eyev;
	t_tuple	normalv;
	int		in_shadow;
}	t_phong_vec;

typedef	struct s_phong_colors
{
	t_tuple	effective;
	t_tuple	ambient;
	t_tuple	difuse;
	t_tuple	specular;
}	t_phong_colors;


t_light		point_light(t_tuple pos, t_tuple color);
t_tuple		lighting(t_material material, t_light l, t_tuple p,	t_phong_vec phong);

#endif