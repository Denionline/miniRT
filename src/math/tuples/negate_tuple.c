/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:42:58 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:42:58 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	negate_tuple(t_tuple t)
{
	if (t.error_code)
		return (t);
	return (
		tuple(
			-t.x,
			-t.y,
			-t.z,
			-t.w
		)
	);
}
