#include "head.h"

int	main(void) {
	float		fov;
	t_camera	cam;
	t_ray		r;

	fov = PI / 2;
	cam = camera(200, 125, fov);
	printf("cam.fov=%f\n",cam.fov);
	printf("cam.pixel_size=%f\n",cam.pixel_size);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	cam = camera(201, 101, fov);
	r = ray_for_pixel(cam, 100, 50);

	printf("Ray for pixel\n");
	printf("r.origin\n");
	print_tuple(r.origin);
	printf("r.direction\n");
	print_tuple(r.direction);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	r = ray_for_pixel(cam, 0, 0);

	printf("Ray for pixel\n");
	printf("r.origin\n");	
	print_tuple(r.origin);
	printf("r.direction\n");	
	print_tuple(r.direction);

	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	cam.transform = multiply_matrix(rotate_y(PI/4), translation(0, -2, 5));
	r = ray_for_pixel(cam, 100, 50);

	printf("Ray for pixel\n");
	printf("r.origin\n");	
	print_tuple(r.origin);
	printf("r.direction\n");	
	print_tuple(r.direction);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	
	t_world 	w;
	t_camera	c;
	t_tuple		from;
	t_tuple		to;
	t_tuple 	up;

	w = default_world();
	c = camera(11, 11, PI / 2);
	from = point(0, 0, -5);
	to = point(0, 0, 0);
	up = vector(0, 1, 0);
	c.transform  = view_transform(from, to, up);
	t_canvas canvas = render(c, w);
	print_tuple(pixel_at(&canvas, 5, 5));
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
