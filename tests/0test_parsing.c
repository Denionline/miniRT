#include "head.h"

int	main(int argc, char *argv[])
{
	t_canvas canvas;
	t_scene	*scene;

	(void)argv;
	(void)argc;
	// if (argc != 2)
	// 	return (1);
	parse_scene(&scene, "scenes/default.rt");
	canvas = render(*scene->camera, *scene->world);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
