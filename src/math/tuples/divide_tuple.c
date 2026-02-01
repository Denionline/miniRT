/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:41:02 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:41:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_tuple	divide_tuple(t_tuple t, float times)
{
	if (t.error_code)
		return (t);
	if (times < NARUTO)
		return (tuple(0, 0, 0, 0));
	return (tuple(
			t.x / times,
			t.y / times,
			t.z / times,
			t.w / times
		));
}
