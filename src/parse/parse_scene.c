#include "head.h"

static int	is_missing_rule(t_scene *scene)
{
	if (!scene->amblight)
		return (TRUE);
	if (!scene->camera)
		return (TRUE);
	if (!scene->world->light.exists)
		return (TRUE);
	return (FALSE);
}

static void	parse_line(t_scene *scene, char *line)
{
	size_t	i;

	if (is_line_empty(line))
		return ;
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'A')
		return (parse_amblight(scene, &scene->amblight, line));
	if (line[i] == 'C')
		return (parse_camera(scene, &scene->camera, line));
	if (line[i] == 'L')
		return (parse_light(scene, &scene->world->light, line));
	if (line[i] == 's' && line[i + 1] == 'p')
		return (parse_object(scene, scene->world, line, SPHERE));
	if (line[i] == 'p' && line[i + 1] == 'l')
		return (parse_object(scene, scene->world, line, PLANE));
	if (line[i] == 'c' && line[i + 1] == 'y')
		return (parse_object(scene, scene->world, line, CYLINDER));
	if (line[i] == 'c' && line[i + 1] == 'o')
		return (parse_object(scene, scene->world, line, CONE));
	end(scene, ERR_UNKNOWN_IDENTIFIER, line, TRUE);
}

void	parse_scene(t_scene **scene, char *file)
{
	const int	file_fd = open(file, O_RDONLY);
	char		*line;

	*scene = saffe_calloc(*scene, NULL, 1, sizeof(t_scene));
	if (file_fd < 0 || !file)
		end(*scene, ERR_OPEN_FILE, file, FALSE);
	(*scene)->world = saffe_calloc(*scene, NULL, 1, sizeof(t_world));
	while (TRUE)
	{
		line = get_next_line(file_fd);
		if (!line)
			break ;
		parse_line(*scene, line);
		free(line);
	}
	if (is_missing_rule(*scene))
		end(*scene, ERR_MISSING, NULL, FALSE);
}
