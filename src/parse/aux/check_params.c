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

void	check_params(char *s, enum N_PARAMS nparams)
{
	size_t	i;

	if (countwords(s, ' ') != nparams)
		exit(42); // Number of params exceeded
	i = 0;
	while (s && s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]))
		{
			if (s[i] != '.' && s[i] != ',' && s[i] != '+' && s[i] != '-')
				exit(42); // Character invalid on params
		}
		i++;
	}
}
