#include "head.h"

static void	parse_line(t_scene *scene, char *line)
{
	if (is_line_empty(line))
		return ;
	while (ft_isspace(*line))
		line++;
	if (*line == 'A')
		return (parse_amblight(&scene->amblight, line + 1));
	if (*line == 'C')
		return (parse_camera(&scene->camera, line + 1));
	if (*line == 'L')
		return (parse_light(&scene->world->light, line + 1));
	if (*line == 's' && *(line + 1) == 'p')
		return (parse_object(scene->world, line, SPHERE));
	if (*line == 'p' && *(line + 1) == 'l')
		return (parse_object(scene->world, line, PLANE));
	if (*line == 'c' && *(line + 1) == 'y')
		return (parse_object(scene->world, line, CYLINDER));
	exit(42); // Type unknown
}

void	parse_scene(t_scene **scene, char *file)
{
	const int	file_fd = open(file, O_RDONLY);
	char		*line;

	if (file_fd < 0)
		exit(42);
	*scene = saffe_calloc(1, sizeof(t_scene));
	(*scene)->world = world();
	while (TRUE)
	{
		line = get_next_line(file_fd);
		if (!line)
			break ;
		parse_line(*scene, line);
		free(line);
	}
}
