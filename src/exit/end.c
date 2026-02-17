/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:31:24 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/17 16:49:14 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	close_fds(void)
{
	int	fd;

	fd = 3;
	while(fd < 100)
		close(fd++);
}

static void	scene_cleaner(t_scene *scene)
{
	size_t	i;

	if (scene)
	{
		if (scene->amblight)
			free(scene->amblight);
		if (scene->camera)
			free(scene->camera);
		if (scene->world)
		{
			if (scene->world->objects)
			{
				i = 0;
				while (i < scene->world->n_objs)
					free(scene->world->objects[i++]);
				free(scene->world->objects);
			}
			free(scene->world);
		}
		free(scene);
	}
}

void	end(t_scene *scene, int status_code, char *description, int to_free)
{
	scene_cleaner(scene);
	if (status_code)
		print_error(status_code);
	if (to_free)
		free(description);
	close_fds();
	exit(status_code);
}
