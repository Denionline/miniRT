/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:06:09 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 19:06:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	parse_object(t_scene *s, t_world *w, char *line, enum e_object_type t)
{
	t_object	*new_object;

	new_object = NULL;
	if (t == SPHERE)
		new_object = parse_sphere(s, line);
	else if (t == PLANE)
		new_object = parse_plane(s, line);
	else if (t == CYLINDER)
		new_object = parse_cylinder(s, line);
	else if (t == CONE)
		new_object = parse_cone(s, line);
	append_object_on_world(w, new_object);
}
