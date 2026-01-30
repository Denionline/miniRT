#include "head.h"

static void	parse_line(t_scene *scene, char *line)
{
	if (is_line_empty(line))
		return ;
	while (ft_isspace(*line))
		line++;
	if (*line == 'A')
		return (parse_amblight(scene, &scene->amblight, line + 1));
	if (*line == 'C')
		return (parse_camera(scene, &scene->camera, line + 1));
	if (*line == 'L')
		return (parse_light(scene, &scene->world->light, line + 1));
	if (*line == 's' && *(line + 1) == 'p')
		return (parse_object(scene, scene->world, line, SPHERE));
	if (*line == 'p' && *(line + 1) == 'l')
		return (parse_object(scene, scene->world, line, PLANE));
	if (*line == 'c' && *(line + 1) == 'y')
		return (parse_object(scene, scene->world, line, CYLINDER));
	end(scene, ERR_UNKNOWN_IDENTIFIER);
}

void	parse_scene(t_scene **scene, char *file)
{
	const int	file_fd = open(file, O_RDONLY);
	char		*line;

	if (file_fd < 0)
		end(*scene, ERR_OPEN_FILE);
	*scene = saffe_calloc(*scene, 1, sizeof(t_scene));
	(*scene)->world = saffe_calloc(*scene, 1, sizeof(t_world));
	while (TRUE)
	{
		line = get_next_line(file_fd);
		if (!line)
			break ;
		parse_line(*scene, line);
		free(line);
	}
}
