/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:20 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 15:48:18 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	normal_at(t_object *object, t_tuple p)
{
	t_tuple		object_point;
	t_tuple		new_object;
	t_matrix	inv;

	if (!object)
		return (tuple(0, 0, 0, 0));
	inv = (object->transform);
	object_point = multiply_matrix_tuple(inv, p);
	new_object = local_normal_at(object, object_point);
	new_object = multiply_matrix_tuple(transpose(inv), new_object);
	new_object = normalize(new_object);
	new_object.w = 0;
	return (new_object);
}
