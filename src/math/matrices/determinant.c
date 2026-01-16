# include "head.h"

float	determ_2d(t_matrix matrix2d)
{
	float (*m)[4];
	
	m = matrix2d.matrix;
	return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

static float	det_cof(t_matrix m_cpy)
{
	unsigned int		j;
	float				cof;

	j = 0;
	cof = 0;
	while (j < m_cpy.size)
	{
		cof += m_cpy.matrix[0][j] * cofactor(m_cpy, 0, j);
		j++;
	}
	return (cof);
}

float	determinant(t_matrix m)
{
	unsigned int	i;
	t_matrix		m_cpy;
	float			det;

	i = 0;
	det = 0;
	m_cpy = m;
	if (m.size == 2)
		return (determ_2d(m));
	while (i < m.size)
	{
		if (m.size == 4)
		{
			m_cpy = submatrix(m, 0, i);
			if (i % 2 != 0)
				det += -1.0f * m.matrix[0][i] * det_cof(m_cpy);
			else
				det += m.matrix[0][i] * det_cof(m_cpy);
		}
		else
			det += m_cpy.matrix[0][i] * cofactor(m_cpy, 0, i);
		i++;
	}
	return (det); 
}
