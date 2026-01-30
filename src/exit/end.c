#include "head.h"

static void	scene_cleaner(t_scene *scene)
{
	size_t	i;

	if (scene)
	{
		if (scene->amblight)
		free(scene->amblight);
		if (scene->camera)
			free(scene->camera);
		if (scene->world && scene->world->n_objs)
		{
			i = 0;
			while (i < scene->world->n_objs)
				free(scene->world->objects[i++]);
			free(scene->world->objects);
		}
		free(scene);
	}
}

void	end(t_scene *scene, enum ERROR_CODE status_code)
{
	scene_cleaner(scene);
	if (status_code)
		print_error(status_code);
	exit(status_code);
}
