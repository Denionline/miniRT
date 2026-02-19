/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:39:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/11/20 12:05:50 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	get_num(const char *str, int i, long sign)
{
	long long	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			return (LLONG_MIN);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

long long	ft_atoll(char *str)
{
	long	sign;
	size_t	i;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (get_num(str, i, sign));
}
