#ifndef MATH_HEAD_H
# define MATH_HEAD_H

#include "head.h"
#include <math.h>

enum TUPLE_TYPES {
	VECTOR,
	POINT,
	COLOR,
};

typedef struct s_tuple
{
	union {
		float	x;
		float	r;
	};
	union {
		float	y;
		float	g;
	};
	union {
		float	z;
		float	b;
	};
	float	w;
}	t_tuple;

int	is_equals(float n1, float n2);

t_tuple	tuple(float x, float y, float z, float w);
t_tuple	vector(float x, float y, float z);
t_tuple	point(float x, float y, float z);
t_tuple	color(float x, float y, float z);

#endif