#ifndef MATH_H
# define MATH_H

#include "head.h"

enum TUPLE_TYPES {
	VECTOR,
	POINT,
	COLOR,
};

typedef struct s_tuple
{
	union {
		struct {float x, y, z, w;};
		struct {uint8_t	r, g, b;};
	};
}	t_tuple;

int	is_equals(float n1, float n2);

t_tuple	tuple(float x, float y, float z, float w);
t_tuple	vector(float x, float y, float z);
t_tuple	point(float x, float y, float z);
t_tuple	color(uint8_t x, uint8_t y, uint8_t z);

#endif