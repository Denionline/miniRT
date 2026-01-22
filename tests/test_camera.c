#include "head.h"

int	main(void) {
	float		fov;
	t_ray		r;
	t_camera	cam;

	fov = PI / 2;
	cam = camera(fov);
	printf("cam.fov=%f\n",cam.fov);
	printf("cam.pixel_size=%f\n",cam.pixel_size);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

}
