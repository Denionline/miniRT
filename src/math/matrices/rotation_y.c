#include "head.h"

t_matrix	rotation_y(double radians)
{
	const double c	= cos(radians);
	const double s	= sin(radians);

	return (
		matrix((float []){
			c, 0, s, 0,
			0, 1, 0, 0,
			-s, 0, c, 0,
			0, 0, 0, 1
		}
		, 4));
}
