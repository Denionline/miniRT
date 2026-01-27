#include "head.h"

int	is_line_empty(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_isspace(line[i]))
			return (FALSE);
		i++;
	}
	return (FALSE);
}

int	is_tuple_empty(t_tuple t)
{
	if (!t.x && !t.y && t.z)
		return (TRUE);
	if (!t.r && !t.g && !t.b)
		return (TRUE);
	return (FALSE);
}

int	is_matrix_empty(t_matrix m)
{
	return (m.size == 0);
}
