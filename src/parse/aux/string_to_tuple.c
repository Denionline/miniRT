#include "head.h"

static int	is_out_of_range(t_tuple v, enum e_TUPLE_TYPES w)
{
	float	max;
	float	min;

	max = 1.0f + NARUTO;
	if (w == COLOR)
		max = 255.0f;
	min = -max;
	if (w == COLOR)
		min = 0.0f;
	if(v.x > max || v.y > max || v.z > max)
		return (TRUE);
	if(v.x < min || v.y < min || v.z < min)
		return (TRUE);
	return (FALSE);
}

static int	is_valid_string(char *str)
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
	size_t	i;

	t = (t_tuple){};
	if (!is_valid_string(string))
		t.error_code = ERR_INVALID_TUPLE;
	t.w = w;
	paramc = 0;
	i = 0;
	while (string && string[i] && paramc < NPARAM_TUPLE)
	{
		if (paramc == 0 && ++paramc)
			t.x = ft_atof(string + i);
		else if (paramc == 1 && ++paramc)
			t.y = ft_atof(string + i);
		else if (paramc == 2 && ++paramc)
			t.z = ft_atof(string + i);
		while (string[i] && string[i++] != ',')
			;
	}
	if (w != POINT && is_out_of_range(t, w))
		t.error_code = ERR_OUT_OF_RANGE;
	return (t);
}
