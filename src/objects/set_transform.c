/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:28:54 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:28:54 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_object	*set_transform(t_object *obj, t_matrix transform)
{
	obj->transform = inverse(transform);
	obj->transform.size = transform.size;
	return (obj);
}
