#include "head.h"

static void	print_tuple(t_tuple t)
{
	const char	*type;

	if (t.w == VECTOR)
		type = "VECTOR";
	else if (t.w == POINT)
		type = "POINT";
	else
		type = "TUPLE";

	printf("┌────────┬─────────┬─────────┬─────────┬─────────┐\n");
	printf("│ %-6s │ %7.2f │ %7.2f │ %7.2f │ %7.2f │\n",
		type, t.x, t.y, t.z, t.w);
	printf("└────────┴─────────┴─────────┴─────────┴─────────┘\n");
}
