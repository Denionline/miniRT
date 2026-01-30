#include "head.h"

static void	parse_line(t_scene *scene, char *line)
{
	size_t	i;

	if (is_line_empty(line))
		return ;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'A')
		return (parse_amblight(scene, &scene->amblight, line + i + 1));
	if (line[i] == 'C')
		return (parse_camera(scene, &scene->camera, line + i + 1));
	if (line[i] == 'L')
		return (parse_light(scene, &scene->world->light, line + i + 1));
	if (line[i] == 's' && line[i + 1] == 'p')
		return (parse_object(scene, scene->world, line + i, SPHERE));
	if (line[i] == 'p' && line[i + 1] == 'l')
		return (parse_object(scene, scene->world, line + i, PLANE));
	if (line[i] == 'c' && line[i + 1] == 'y')
		return (parse_object(scene, scene->world, line + i, CYLINDER));
	end(scene, ERR_UNKNOWN_IDENTIFIER, line);
}

void	parse_scene(t_scene **scene, char *file)
{
	const int	file_fd = open(file, O_RDONLY);
	char		*line;

	if (file_fd < 0)
		end(*scene, ERR_OPEN_FILE, file);
	*scene = saffe_calloc(*scene, 1, sizeof(t_scene), NULL);
	(*scene)->world = saffe_calloc(*scene, 1, sizeof(t_world), NULL);
	while (TRUE)
	{
		line = get_next_line(file_fd);
		if (!line)
			break ;
		parse_line(*scene, line);
		free(line);
	}
}
