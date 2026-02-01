/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_tuple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:40:54 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:40:54 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	multiply_tuple(t_tuple t, float times)
{
	if (t.error_code)
		return (t);
	return (
		tuple(
			t.x * times,
			t.y * times,
			t.z * times,
			t.w * times
		)
	);
}
