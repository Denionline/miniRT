#include "head.h"

int main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 440, "Arroba");
	mlx_loop(mlx);
	return (0);
}