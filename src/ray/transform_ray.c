/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:02 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:33:03 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_ray	transform_ray(t_ray r, t_matrix m)
{
	r.origin = multiply_matrix_tuple(m, r.origin);
	r.direction = multiply_matrix_tuple(m, r.direction);
	return (r);
}
