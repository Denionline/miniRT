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
	size_t	paramc;
	t_tuple	t;

	if (!is_valid_tuple(string))
		exit(42); // Invalid tuple
	t = (t_tuple){};
	paramc = 0;
	t.w = w;
	while (string && *string && paramc < 3)
	{
		if (paramc == 0 && ++paramc)
			t.x = ft_atof(string);
		else if (paramc == 1 && ++paramc)
			t.y = ft_atof(string);
		else if (paramc == 2 && ++paramc)
			t.z = ft_atof(string);
		while (*string && *(string++) != ',')
			;
	}
	return (t);
}
