/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:59:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 10:27:41 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_invalid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (TRUE);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (TRUE);
		if ((base[i] >= '\a' && base[i] <= '\r') || base[i] == ' ')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	find_n_in_base(char pos, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == pos)
			return (i);
		i++;
	}
	return (-1);
}

static int	skip_conditions(char *str, int *m)
{
	int	i;

	i = 0;
	*m = 0;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*m += 1;
		i++;
	}
	return (i);
}

int	ft_basetoi(char *str, char *base)
{
	int	base_size;
	int	nbr_base;
	int	result;
	int	minus;
	int	i;

	base_size = ft_strlen(base);
	minus = 0;
	if (is_invalid_base(base) || base_size < 2)
		return (0);
	i = skip_conditions(str, &minus);
	result = 0;
	while (str[i])
	{
		nbr_base = find_n_in_base(ft_tolower(str[i]), base);
		if (nbr_base < 0)
			return (0);
		result = result * base_size + nbr_base;
		i++;
	}
	if ((minus % 2) != 0)
		return (-result);
	return (result);
}
