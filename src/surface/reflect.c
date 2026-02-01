/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:20 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 15:49:21 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (subtract_tuples(
			in,
			multiply_tuple(
				normal,
				2 * dot(in, normal)
			)
		));
}
