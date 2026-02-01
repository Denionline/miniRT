/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_patterns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:28:49 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 19:17:31 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_pattern	ring_pattern(t_tuple color1, t_tuple color2,
		enum e_object_type type)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.transform = identity_matrix();
	p.has_pattern = 1;
	p.type_p = RING;
	p.tpye_obj = type;
	return (p);
}

t_pattern	stripe_pattern(t_tuple color1, t_tuple color2,
		enum e_object_type type)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.transform = identity_matrix();
	p.has_pattern = 1;
	p.type_p = STRIP;
	p.tpye_obj = type;
	return (p);
}

t_pattern	gradient_pattern(t_tuple color1, t_tuple color2,
		enum e_object_type type)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.transform = identity_matrix();
	p.has_pattern = 1;
	p.type_p = GRADIENT;
	p.tpye_obj = type;
	return (p);
}

t_pattern	checkboard_pattern(t_tuple color1, t_tuple color2,
		enum e_object_type type)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.transform = identity_matrix();
	p.has_pattern = 1;
	p.type_p = CHECKBOARD;
	p.tpye_obj = type;
	p.width = 10;
	p.height = 10;
	if (type == PLANE)
	{
		p.width = 2;
		p.height = 2;
	}
	return (p);
}
