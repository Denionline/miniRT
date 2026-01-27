#include "head.h"

void	parse_line(t_scene *scene, char *line)
{
	int	i;

	if (is_line_empty(line))
		return ;
	i = -1;
	while (line && line[++i])
	{
		if (ft_isspace(line[i]))
			continue;
		if (line[i] == 'A')
			return (parse_amblight(&scene->amblight, line + i));
		if (line[i] == 'C')
			return (parse_camera(&scene->camera, line + i));
		if (line[i] == 'L')
			return (parse_light(&scene->world, line + i));
		if (line[i] == 's' && line[i + 1] == 'p')
			return (parse_object(&scene->world, line + i, SPHERE));
		if (line[i] == 'p' && line[i + 1] == 'l')
			return (parse_object(&scene->world, line + i, PLANE));
		if (line[i] == 'c' && line[i + 1] == 'y')
			return (parse_object(&scene->world, line + i, CYLINDER));
	}
}

void	parse_scene(t_scene *scene, char *file)
{
	const int	file_fd = open(file, O_RDONLY);
	char		*line;

	if (file_fd < 0)
		exit(42);
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		exit(42);
	*scene = (t_scene){};
	while (TRUE)
	{
		line = get_next_line(file_fd);
		if (!line)
			break ;
		parse_line(scene, line);
		free(line);
	}
}

// .amblight = (t_amblight) {
// 	.ratio = 0.2,
// 	.color = color(255, 255, 255)
// },
// .camera = (t_camera) {
// 	.position = point(-50.0, 0.0, 20.0),
// 	.orientation = vector(0.0, 0.0, 1.0),
// 	.fov = 70,
// },
// .light = &(t_light) {
// 	.position = point(-40.0, 50.0, 0.0),
// 	.brightness = 0.6,
// 	.color = color(10, 0, 255)
// },
// .object = &(t_object) {
// 	.type = SPHERE,
// 	.position = point(0.0, 0.0, 20.6),
// 	.color = color(10, 0, 255),
// 	.options = &(t_sphere) {
// 		.diameter = 12.6,
// 	},
// }