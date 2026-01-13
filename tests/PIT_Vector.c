#include "head.h"

typedef struct s_proj
{
	t_tuple	position;
	t_tuple	velocity;
} t_proj;

typedef struct s_env
{
	t_tuple	gravity;
	t_tuple	wind;
} t_env;

t_proj	tick(t_proj proj, t_env env)
{
	t_tuple new_position;
	t_tuple	new_vel;

	new_vel = sum_tuples(proj.velocity, sum_tuples(env.gravity, env.wind));
	new_position = sum_tuples(proj.position, new_vel);
	return ((t_proj) {.position = new_position, .velocity = new_vel});
}

int main(void)
{
	t_canvas	canvas;
	t_tuple		new_color;
	t_proj		projectile;
	t_env		env;

	new_color = color(0, 0, 255);
	projectile = (t_proj) {.position = point(0, 1, 0), .velocity = multiply_tuple(normalize(vector(1, 1.8, 0)), 11.25)};
	env = (t_env) {.gravity = vector(0, -0.1, 0), .wind = vector(-0.01, 0, 0)};

	init_canvas(&canvas);
	for (; projectile.position.y > 0;)
	{
		pixel_put(&canvas, projectile.position.x, projectile.position.y, new_color);
		new_color = sum_color(new_color, color(projectile.position.x, projectile.position.y, new_color.b - 1));
		projectile = tick(projectile, env);
	}
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
