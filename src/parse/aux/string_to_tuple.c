#include "head.h"

static int	is_valid_tuple(char *str)
{
	size_t	commas;
	size_t	dots;
	size_t	i;

	commas = 0;
	dots = 0;
	i = 0;
	while (str && str[i] && !ft_isspace(str[i]))
	{
		if (str[i] == '.')
			dots += 1;
		if (str[i] == ',')
			commas += 1;
		i++;
	}
	return ((dots <= 3 && commas == 2));
}

t_tuple	string_to_tuple(char *string, enum e_TUPLE_TYPES w)
{
	t_tuple	t;
	size_t	i;

	if (is_valid_tuple(string))
		exit(42); // Invalid tuple
	t = (t_tuple){};
	i = 0;
	while (string && string[i])
	{
		if (!t.x)
			t.x = ft_atof(string);
		else if (!t.y)
			t.y = ft_atof(string);
		else if (!t.z)
			t.z = ft_atof(string);
		else if (!t.w)
			t.w = w;
		while (string[i] && string[i++] != ',');
	}
	return (t);
}
