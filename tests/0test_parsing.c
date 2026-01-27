#include "head.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;

	(void)argv;
	if (argc =! 2)
		return (1);
	parse_scene(&scene, "scenes/default.rt");
}
