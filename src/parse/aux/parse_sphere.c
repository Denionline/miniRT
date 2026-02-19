/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:02:13 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/19 12:28:02 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	error_check(t_object *sphere, int *error_code)
{
	*error_code = 0;
	if (sphere->position.error_code)
		*error_code = sphere->position.error_code;
	if (sphere->material.color.error_code)
		*error_code = sphere->material.color.error_code;
	return (*error_code);
}

static t_pattern	check_pattern(char *line)
{
	if (line[0] == 'c' && line[1] == 'k')
		return (checkboard_pattern(color_float(1, 1, 1),
				color_float(0, 0, 0), SPHERE));
	if (line[0] == 's' && line[1] == 't')
		return (stripe_pattern(color_float(1, 1, 1),
				color_float(0, 0, 0), SPHERE));
	if (line[0] == 'r' && line[1] == 'g')
		return (ring_pattern(color_float(1, 1, 1),
				color_float(1, 0, 0), SPHERE));
	if (line[0] == 'g' && line[1] == 'r')
		return (gradient_pattern(color_float(1, 0, 0),
				color_float(252 / 255.0f, 15 / 255.0f, 192 / 255.0f), SPHERE));
	return ((t_pattern){});
}

static int	check_cond(size_t *paramc, t_object *new_sphere, char *line)
{
	if ((*paramc) == 0 && *line == 's')
		line += 2;
	else if ((*paramc) == 0 && ++(*paramc))
		new_sphere->position = string_to_tuple(line, POINT);
	else if ((*paramc) == 1 && ++(*paramc))
		new_sphere->diameter = ft_atof(line);
	else if ((*paramc) == 2 && ++(*paramc))
		new_sphere->material = material(
				multiply_tuple(
					string_to_tuple(line, COLOR),
					1.0f / 255.0f
					)
				);
	else if ((*paramc) == 3 && ++(*paramc))
	{
		if (*line != '\n')
		{
			new_sphere->material.pattern = check_pattern(line);
			if (!new_sphere->material.pattern.has_pattern)
				return (0);
		}
	}
	return (1);
}

static int	fill_values(t_object *new_sphere, char *line)
{
	size_t	paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_SPHERE - 1)
	{
		while (ft_isspace(*line))
			line++;
		if (!check_cond(&paramc, new_sphere, line))
			return (0);
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (1);
}

t_object	*parse_sphere(t_scene *scene, char *line)
{
	t_object	*new_sphere;
	float		radius;
	int			error_code;

	check_params(scene, line, NPARAM_SPHERE, 0);
	new_sphere = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_sphere->type = SPHERE;
	error_code = ERR_INVALID_CHAR;
	if (!fill_values(new_sphere, line) || error_check(new_sphere, &error_code))
	{
		free(new_sphere);
		end(scene, error_code, line, TRUE);
	}
	radius = new_sphere->diameter * 0.5f;
	new_sphere->transform = multiply_matrix(translation(new_sphere->position.x, \
new_sphere->position.y, new_sphere->position.z), \
scaling(radius, radius, radius));
	new_sphere->transform = inverse(new_sphere->transform);
	return (new_sphere);
}
