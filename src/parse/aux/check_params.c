#include "head.h"

static int	countwords(char *str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
			cnt++;
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	return (cnt);
}

static int	is_identifier(char *s)
{
	if (s[0] == 'A')
		return (1);
	if (s[0] == 'C')
		return (1);
	if (s[0] == 'L')
		return (1);
	if (s[0] == 'p' && s[1] == 'l')
		return (2);
	if (s[0] == 's' && s[1] == 'p')
		return (2);
	if (s[0] == 'c' && s[1] == 'y')
		return (2);
	return (0);
}

void	check_params(t_scene *scene, char *s, int nparams, int exists)
{
	size_t	id_len;
	size_t	i;

	if (exists)
		end(scene, ERR_DUPLICATE, s, TRUE);
	if (countwords(s) != nparams)
		end(scene, ERR_OUT_OF_RANGE, s, TRUE);
	i = 0;
	while (s && s[i])
	{
		id_len = is_identifier(s + i);
		if (id_len)
			i += id_len;
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
		{
			if (s[i] != '.' && s[i] != ',' && s[i] != '+' && s[i] != '-')
				end(scene, ERR_INVALID_CHAR, s, TRUE);
		}
		i++;
	}
}
