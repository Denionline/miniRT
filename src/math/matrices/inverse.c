#include "head.h"

t_matrix	inverse(t_matrix m)
{
	t_matrix		inv_m;
	float			det;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	inv_m = (t_matrix) {.size = m.size};
	det = determinant(m);
	if (det == 0)
		return (identity_matrix());
	det = 1 / det;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			inv_m.matrix[j][i] = cofactor(m, i, j) * det;
			j++;
		}
		i++;
	}
	return (inv_m);
}
