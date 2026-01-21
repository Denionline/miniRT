#include "head.h"

void	print_color(t_tuple c)
{
	t_tuple	t;
	const char	*type;

	t = color(c.x, c.y, c.z);

	type = "COLOR";

	printf("\033[38;2;%d;%d;%dm┌────────┬─────────┬─────────┬─────────┐\n", (int) t.r, (int) t.g, (int) t.b);
	printf("│ %-6s │ %.3d 	   │ %.3d     │ %.3d     │\n",
		type, (int) t.r, (int) t.g, (int) t.b);
	printf("└────────┴─────────┴─────────┴─────────┘\033[0m\n");
}
