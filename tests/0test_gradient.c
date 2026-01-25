#include "head.h"

int	main(void) {
	Given pattern = gradient_pattern(white, black);
	Then pattern_at(pattern, point(0, 0, 0)) = white;
	And pattern_at(pattern, point(0.25, 0, 0)) = color(0.75, 0.75, 0.75);
	And pattern_at(pattern, point(0.5, 0, 0)) = color(0.5, 0.5, 0.5);
	And pattern_at(pattern, point(0.75, 0, 0)) = color(0.25, 0.25, 0.25);
}
