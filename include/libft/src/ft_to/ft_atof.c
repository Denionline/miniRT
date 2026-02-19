/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:54:33 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/19 09:57:53 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *str)
{
	float	result;
	float	fraction;
	int		sign;

	result = 0.0f;
	fraction = 0.1f;
	sign = 1;
	if (*str == '-' && str++)
		sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.' && str++)
	{
		while (*str >= '0' && *str <= '9')
		{
			result += (*str - '0') * fraction;
			fraction *= 0.1f;
			str++;
		}
	}
	return (result * sign);
}
