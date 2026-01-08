#ifndef MAP_H
# define MAP_H

#include "head.h"

enum object_type {
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_cylinder
{
	float	diameter;
	float	height;
}	t_cylinder;

typedef struct s_sphere
{
	float	diameter;
}	t_sphere;

typedef struct s_object
{
	unsigned int	type;
	t_vector		position;
	t_vector		color;
	void			*options;
}	t_object;

typedef struct s_amblight
{
	float		ratio;
	t_vector	color;
}	t_amblight;

typedef struct s_camera
{
	t_vector	position;
	t_vector	orientation;
	float		fov;
}	t_camera;

typedef struct s_light
{
	t_vector	position;
	float		brightness;
	t_vector	color;
}	t_light;


typedef struct s_map
{
	t_amblight	amblight;
	t_camera	camera;
	t_light		*light;
	t_object	*object;
}	t_map;

t_map	get_map(void);

#endif