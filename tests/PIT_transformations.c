#include "head.h"

int	main(void) {
	t_canvas	canvas;
	t_tuple		new_color = color(255, 255, 255);
	t_tuple		p;
	t_matrix	A;
	t_matrix	B;
	t_matrix	C;
	t_matrix	T;

	init_canvas(&canvas);

	p = point(0, 0, 0);
	A = rotation_z(PI / 6);
	B = scaling(2, 2, 1);
	C = translation(WIDTH / 2, HEIGHT / 2, 0);

	T = multiply_matrix(C , multiply_matrix(B, A));
	T = multiply_matrix(C, multiply_matrix(B,rotation_z(PI / 6)));

	p = multiply_matrix_tuple(T, p);
	print_tuple(p);
	pixel_put(&canvas, p.x, p.y, new_color);
	
	for (int i = 0; i < 12; i++)
	{
		p = multiply_matrix_tuple(rotation_z(i * PI / 6), p);
		print_tuple(p);
		pixel_put(&canvas, p.x, p.y, new_color);
	}
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}




// int	main(void) {
// 	t_canvas	canvas;
// 	t_tuple		new_color = color(0, 0, 255);
// 	t_tuple		p;
// 	t_matrix	A;
// 	t_matrix	B;
// 	t_matrix	C;
// 	t_matrix	T;

// 	init_canvas(&canvas);

// 	p = point(0, 1, 0);
// 	A = rotation_z(PI / 6);
// 	B = scaling(100, 100, 1);
// 	C = translation(WIDTH / 2, HEIGHT / 2, 0);

// 	T = multiply_matrix(C , multiply_matrix(B, A));
	
// 	for (int i = 0; i < 12; i++)
// 	{
// 		T = multiply_matrix(C, multiply_matrix(B,rotation_z(i * PI / 6)));

// 		t_tuple hour = multiply_matrix_tuple(T, p);
// 		print_tuple(hour);
// 		pixel_put(&canvas, hour.x, hour.y, new_color);
// 	}
// 	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
// 	ft_init_hooks(&canvas);
// 	mlx_loop(canvas.mlx_ptr);
// }
