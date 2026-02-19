/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:59:49 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/19 12:28:10 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	error_check(t_object *plane, int *error_code)
{
	*error_code = 0;
	if (plane->position.error_code)
		*error_code = plane->position.error_code;
	else if (plane->normal.error_code)
		*error_code = plane->normal.error_code;
	else if (plane->material.color.error_code)
		*error_code = plane->material.color.error_code;
	return (*error_code);
}

static t_pattern	check_pattern(char *line)
{
	if (line[0] == 'c' && line[1] == 'k')
		return (checkboard_pattern(color_float(1, 1, 1),
				color_float(0, 0, 0), PLANE));
	if (line[0] == 's' && line[1] == 't')
		return (stripe_pattern(color_float(1, 1, 1),
				color_float(0, 0, 0), PLANE));
	if (line[0] == 'r' && line[1] == 'g')
		return (ring_pattern(color_float(1, 1, 1),
				color_float(1, 0, 0), PLANE));
	if (line[0] == 'g' && line[1] == 'r')
		return (gradient_pattern(color_float(1, 0, 0),
				color_float(252 / 255.0f, 15 / 255.0f, 192 / 255.0f), PLANE));
	return ((t_pattern){});
}

static int	check_cond(size_t *paramc, t_object *new_plane, char *line)
{
	if ((*paramc) == 0 && *line == 'p')
		line += 2;
	else if ((*paramc) == 0 && ++(*paramc))
		new_plane->position = string_to_tuple(line, POINT);
	else if ((*paramc) == 1 && ++(*paramc))
		new_plane->normal = normalize(
				string_to_tuple(line, VECTOR));
	else if ((*paramc) == 2 && ++(*paramc))
		new_plane->material = material(
				multiply_tuple(
					string_to_tuple(line, COLOR),
					1.0f / 255.0f
					)
				);
	else if ((*paramc) == 3 && ++(*paramc))
	{
		if (*line != '\n')
		{
			new_plane->material.pattern = check_pattern(line);
			if (!new_plane->material.pattern.has_pattern)
				return (0);
		}
	}
	return (1);
}

static int	fill_values(t_object *new_plane, char *line)
{
	size_t		paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_PLANE - 1)
	{
		while (ft_isspace(*line))
			line++;
		if (!check_cond(&paramc, new_plane, line))
			return (0);
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (1);
}

t_object	*parse_plane(t_scene *scene, char *line)
{
	t_object	*new_plane;
	t_tuple		p;
	int			error_code;

	check_params(scene, line, NPARAM_PLANE, 0);
	new_plane = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_plane->type = PLANE;
	error_code = ERR_INVALID_CHAR;
	if (!fill_values(new_plane, line) || error_check(new_plane, &error_code))
		end(scene, error_code, line, TRUE);
	p = new_plane->position;
	new_plane->transform = multiply_matrix(translation(p.x, p.y, p.z), \
geral_rotation(new_plane->normal));
	new_plane->transform = inverse(new_plane->transform);
	new_plane->material.pattern.transform = new_plane->transform;
	return (new_plane);
}
