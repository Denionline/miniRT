#include "head.h"

t_matrix	multiply_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix	m;
	unsigned	r;
	unsigned	c;

	m.size = m1.size;
	r = 0;
	while (r < m.size)
	{
		c = 0;
		while (c < m.size)
		{
			m.matrix[r][c] = (m1.matrix[r][0] * m2.matrix[0][c]);
			m.matrix[r][c] += (m1.matrix[r][1] * m2.matrix[1][c]);
			m.matrix[r][c] += (m1.matrix[r][2] * m2.matrix[2][c]);
			m.matrix[r][c] += (m1.matrix[r][3] * m2.matrix[3][c]);
			c++;
		}
		r++;
	}
	return (m);
}
