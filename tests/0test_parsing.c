#include "head.h"

int	main(int argc, char *argv[])
{
	t_scene	*scene;

	(void)argv;
	(void)argc;
	// if (argc != 2)
	// 	return (1);
	parse_scene(&scene, "scenes/default.rt");
	print_scene(scene);
}
