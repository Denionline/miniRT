#include "head.h"

t_matrix	rotation_z(double radians)
{
	const double c	= cos(radians);
	const double s	= sin(radians);

	return (
		matrix((float []){
			c, -s, 0, 0,
			s, c, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		}
		, 4));
}
