/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:55:52 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/18 10:42:38 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	error_check(t_object *cylinder, int *error_code)
{
	*error_code = 0;
	if (cylinder->position.error_code)
		*error_code = cylinder->position.error_code;
	if (cylinder->normal.error_code)
		*error_code = cylinder->normal.error_code;
	if (cylinder->material.color.error_code)
		*error_code = cylinder->material.color.error_code;
	return (*error_code);
}

static t_pattern	check_pattern(char *line)
{
	if (line[0] == 'c' && line[1] == 'k')
		return (checkboard_pattern(
				color_float(1, 1, 1),
				color_float(0, 0, 0),
				CYLINDER)
		);
	if (line[0] == 's' && line[1] == 't')
		return (stripe_pattern(
				color_float(1, 1, 1),
				color_float(0, 0, 0),
				CYLINDER)
		);
	if (line[0] == 'r' && line[1] == 'g')
		return (ring_pattern(
				color_float(1, 1, 1),
				color_float(1, 0, 0),
				CYLINDER)
		);
	if (line[0] == 'g' && line[1] == 'r')
		return (gradient_pattern(
				color_float(1, 0, 0),
				color_float(252 / 255.0f, 15 / 255.0f, 192 / 255.0f),
				CYLINDER)
		);
	return ((t_pattern){});
}

static int	check_cond(size_t *paramc, t_object *new_cy, char *line)
{
	if ((*paramc) == 0 && *line == 'c')
		line += 2;
	else if ((*paramc) == 0 && ++(*paramc))
		new_cy->position = string_to_tuple(line, POINT);
	else if ((*paramc) == 1 && ++(*paramc))
		new_cy->normal = normalize(
				string_to_tuple(line, VECTOR));
	else if ((*paramc) == 2 && ++(*paramc))
		new_cy->diameter = ft_atof(line);
	else if ((*paramc) == 3 && ++(*paramc))
		new_cy->height = ft_atof(line);
	else if ((*paramc) == 4 && ++(*paramc))
		new_cy->material = material(multiply_tuple(
					string_to_tuple(line, COLOR), 1.0f / 255.0f));
	else if ((*paramc) == 5 && ++(*paramc))
	{
		if (*line != '\n')
		{
			new_cy->material.pattern = check_pattern(line);
			if (!new_cy->material.pattern.has_pattern)
				return (0);
		}
	}
	return (1);
}

static int	fill_values(t_object *new_cy, char *line)
{
	size_t		paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_CYLINDER)
	{
		while (ft_isspace(*line))
			line++;
		if (!check_cond(&paramc, new_cy, line))
			return (0);
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (1);
}

t_object	*parse_cylinder(t_scene *scene, char *line)
{
	t_object	*new_cy;
	t_tuple		p;
	float		radius;
	int			error_code;

	check_params(scene, line, NPARAM_CYLINDER, 0);
	new_cy = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_cy->type = CYLINDER;
	error_code = ERR_INVALID_CHAR;
	if (!fill_values(new_cy, line) || error_check(new_cy, &error_code))
	{
		free(new_cy);
		end(scene, error_code, line, TRUE);
	}
	p = new_cy->position;
	radius = new_cy->diameter * 0.5f;
	new_cy->transform = geral_rotation(new_cy->normal);
	new_cy->transform = multiply_matrix(
			scaling(radius, new_cy->height, radius),
			new_cy->transform);
	new_cy->transform = multiply_matrix(
			translation(p.x, p.y, p.z),
			new_cy->transform);
	new_cy->transform = inverse(new_cy->transform);
	return (new_cy);
}
