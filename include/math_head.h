#ifndef MATH_HEAD_H
# define MATH_HEAD_H

# include "head.h"

# define NARUTO 0.01
# define PI 3.14159

enum e_TUPLE_TYPES {
	VECTOR,
	POINT,
	COLOR,
};

typedef struct s_tuple
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
			float	w;
		};
		struct
		{
			uint8_t	r;
			uint8_t	g;
			uint8_t	b;
		};
	};
}	t_tuple;

int		is_equals(float n1, float n2);

t_tuple	tuple(float x, float y, float z, float w);
t_tuple	vector(float x, float y, float z);
t_tuple	point(float x, float y, float z);
t_tuple	color(t_tuple color_f);
t_tuple	color_float(float x, float y, float z);

t_tuple	sum_tuples(t_tuple t1, t_tuple t2);
t_tuple	subtract_tuples(t_tuple t1, t_tuple t2);
t_tuple	negate_tuple(t_tuple t);
t_tuple	multiply_tuple(t_tuple tuple, float times);
t_tuple	divide_tuple(t_tuple tuple, float times);
float	magnitude(t_tuple t);
t_tuple	normalize(t_tuple t);
float	dot(t_tuple t1, t_tuple t2);
t_tuple	cross(t_tuple t1, t_tuple t2);
t_tuple	multiply_tuple_tuple(t_tuple t1, t_tuple t2);

#endif