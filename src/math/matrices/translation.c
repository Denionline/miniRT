#include "head.h"

t_matrix	translation(float x, float y, float z)
{
	t_matrix	m;

	m = identity_matrix();
	m.matrix[0][m.size - 1] = x;
	m.matrix[1][m.size - 1] = y;
	m.matrix[2][m.size - 1] = z;
	return (m);
}
