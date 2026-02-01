/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:31:18 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 15:08:49 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_light	point_light(t_tuple pos, t_tuple color, float brightness)
{
	return ((t_light){
		.position = pos,
		.intensity = multiply_tuple(color, brightness)
	});
}
