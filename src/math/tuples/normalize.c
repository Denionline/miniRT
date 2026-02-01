/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:43:16 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:43:17 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	normalize(t_tuple t)
{
	const float	mag = 1.0f / magnitude(t);

	if (t.error_code)
		return (t);
	return (
		tuple(
			t.x * mag,
			t.y * mag,
			t.z * mag,
			t.w * mag
		)
	);
}
