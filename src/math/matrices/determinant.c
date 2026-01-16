# include "head.h"

float	determ_2d(t_matrix matrix2d)
{
	float (*m)[4];
	
	m = matrix2d.matrix;
	return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}
