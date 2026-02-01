/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_object_on_world.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:25 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:33:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	append_object_on_world(t_world *w, t_object *new_object)
{
	t_object	**objects;
	size_t		i;

	objects = ft_calloc(w->n_objs + 1, sizeof(t_object *));
	if (!objects)
		exit(42);
	i = 0;
	while (i < w->n_objs)
	{
		objects[i] = w->objects[i];
		i++;
	}
	objects[i] = new_object;
	free(w->objects);
	w->objects = objects;
	w->n_objs += 1;
}
