/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:06 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:33:08 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_intersection	intersection(float value_of, t_object *object)
{
	return (
		(t_intersection) {
			.t = value_of,
			.object = object,
		}
	);
}
