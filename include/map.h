#ifndef MAP_H
# define MAP_H

#include "head.h"

enum object_type {
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_object
{
	enum object_type	type;
	t_tuple				position;
	t_tuple				color;
	t_matrix			transform;
	t_material			material;
	float				diameter;
	float				height;
}	t_object;

typedef struct s_amblight
{
	float		ratio;
	t_tuple	color;
}	t_amblight;

typedef struct s_camera
{
	t_tuple	position;
	t_tuple	orientation;
	float		fov;
}	t_camera;

typedef struct s_map
{
	t_amblight	amblight;
	t_camera	camera;
	t_light		*light;
	t_object	*object;
}	t_map;

t_map	get_map(void);

#endif