#include "head.h"

static size_t	countwords(char *str, char sep)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
			cnt++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (cnt);
}

static int	is_identifier(char *s)
{
	if (s[0] == 'A')
		return (TRUE);
	if (s[0] == 'C')
		return (TRUE);
	if (s[0] == 'L')
		return (TRUE);
	if (s[0] == 'p' && s[1] == 'l')
		return (TRUE);
	if (s[0] == 's' && s[1] == 'p')
		return (TRUE);
	if (s[0] == 'c' && s[1] == 'y')
		return (TRUE);
	return (FALSE);
}

void	check_params(t_scene *scene, char *s, enum N_PARAMS nparams)
{
	size_t	i;

	if (countwords(s, ' ') != nparams)
		end(scene, ERR_OUT_OF_RANGE, s, TRUE);
	i = 0;
	while (s && s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]) && !is_identifier(s + i))
		{
			if (s[i] != '.' && s[i] != ',' && s[i] != '+' && s[i] != '-')
				end(scene, ERR_INVALID_CHAR, s, TRUE);
		}
		i++;
	}
}
