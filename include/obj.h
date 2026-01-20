#ifndef OBJ_H
# define OBJ_H

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
	float				diameter;
	float				height;
}	t_object;

t_object	*set_transform(t_object *obj, t_matrix transform);

#endif