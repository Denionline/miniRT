#ifndef OBJ_H
# define OBJ_H

#include "light.h"
#include "ray.h"

enum object_type {
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
};

enum pattern_type {
	STRIP,
	GRADIENT,
	RING,
	CHECKBOARD
};

typedef struct s_pattern 
{
	enum pattern_type	type;
	t_matrix			transform;
	t_tuple				a;
	t_tuple				b;
	int					has_pattern;
}	t_pattern;

typedef	struct s_material
{
	t_pattern	pattern;
	t_tuple		color;
	float		ambient;
	float		difuse;
	float		specular;
	float		shininess;
}	t_material;

typedef struct s_object
{
	enum object_type	type;
	t_tuple				position;
	t_matrix			transform;
	t_material			material;
	float				diameter;
	float				height;
	t_tuple				normal;
}	t_object;

t_object		*set_transform(t_object *obj, t_matrix transform);
t_object		*sphere(void);
t_object		*plane(void);
t_object		*cylinder(void);
t_object		*cone(void);

t_material		material(t_tuple color);

t_intersections	local_intersect(t_object *obj, t_ray r);
t_tuple			local_normal_at(t_object *obj, t_tuple p);

t_tuple		stripe_at(t_pattern p, t_tuple pos);
t_tuple		stripe_at_obj(t_pattern p, t_object obj, t_tuple pos);
t_pattern	stripe_pattern(t_tuple color1, t_tuple color2);
t_tuple		pattern_at(t_pattern pat, t_tuple p);
t_tuple		pattern_at_obj(t_pattern p, t_object obj, t_tuple pos);
t_pattern	gradient_pattern(t_tuple color1, t_tuple color2);
t_pattern	ring_pattern(t_tuple color1, t_tuple color2);
t_pattern	checkboard_pattern(t_tuple color1, t_tuple color2);
#endif