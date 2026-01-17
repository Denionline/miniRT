# include "head.h"

float	determinant(t_matrix m)
{
	unsigned int	i;
	t_matrix		m_cpy;
	float			det;

	i = 0;
	det = 0;
	m_cpy = m;
	if (m.size == 2)
		return (m.matrix[0][0] * m.matrix[1][1] - m.matrix[0][1] * m.matrix[1][0]);
	while (i < m.size)
	{
		det += m_cpy.matrix[0][i] * cofactor(m_cpy, 0, i);
		i++;
	}
	return (det); 
}
