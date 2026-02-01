/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:04 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 19:12:23 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

// Return the position of the ray after t units of time
t_tuple	position(t_ray r, float t)
{
	return (sum_tuples(r.origin, multiply_tuple(r.direction, t)));
}
