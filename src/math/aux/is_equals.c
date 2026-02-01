/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:30:55 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:30:56 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	is_equals(float n1, float n2)
{
	if (fabsf(n1 - n2) < NARUTO)
		return (TRUE);
	return (FALSE);
}
