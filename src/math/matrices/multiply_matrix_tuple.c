/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_tuple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:30:14 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:30:15 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	multiply_matrix_tuple(t_matrix matrix, t_tuple t)
{
	const float	(*m)[4] = matrix.matrix;

	return (
		(t_tuple) {
			.x = m[0][0] * t.x + m[0][1] * t.y + m[0][2] * t.z + m[0][3] * t.w,
			.y = m[1][0] * t.x + m[1][1] * t.y + m[1][2] * t.z + m[1][3] * t.w,
			.z = m[2][0] * t.x + m[2][1] * t.y + m[2][2] * t.z + m[2][3] * t.w,
			.w = m[3][0] * t.x + m[3][1] * t.y + m[3][2] * t.z + m[3][3] * t.w
		}
	);
}
