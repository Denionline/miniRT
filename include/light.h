#ifndef LIGHT_H
# define LIGHT_H

#include "head.h"

typedef struct s_light
{
	t_tuple	position;
	t_tuple	intensity;
}	t_light;

typedef	struct s_material
{
	t_tuple	color;
	float	ambient;
	float	difuse;
	float	specular;
	float	shininess;
}	t_material;

typedef	struct s_env_eye
{
	t_tuple	point;
	t_tuple	eyev;
	t_tuple	normalv;
}	t_env_eye;


t_light	point_light(t_tuple pos, t_tuple color);
#endif