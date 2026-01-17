#include "head.h"

t_matrix	scaling(float x, float y, float z)
{
	t_matrix		m;

	m = identity_matrix();
	m.matrix[0][0] = x;
	m.matrix[1][1] = y;
	m.matrix[2][2] = z;
	return (m);	
}
