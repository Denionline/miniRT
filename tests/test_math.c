#include "head.h"
#include <stdio.h>

static void	print_tuple(t_tuple t) {
	if (t.w == VECTOR)
		printf("%6s", "Vector");
	else if (t.w == POINT)
		printf("%6s", "Point");
	else
		printf("%6s", "Tuple");
	printf(" | x: %6.2f | y: %6.2f | z: %6.2f | w: %6.2f\n", t.x, t.y, t.z, t.w);
}

static void	sum_test(char *title) {
	printf("----------%s----------\n", title);
	
	t_tuple	t1 = tuple(3, -2, 5, 1);
	t_tuple	t2 = tuple(-2, 3, 1, 0);
	print_tuple(t1);
	print_tuple(t2);
	print_tuple(sum_tuples(t1, t2));
}

static void	subtract_test(char *title) {
	printf("----------%s----------\n", title);
	t_tuple	t1;
	t_tuple	t2;
	
	t1 = point(3, 2, 1);
	t2 = point(5, 6, 7);
	print_tuple(t1);
	print_tuple(t2);
	print_tuple(subtract_tuples(t1, t2));
	
	printf("\n");
	t1 = point(3, 2, 1);
	t2 = vector(5, 6, 7);
	print_tuple(t1);
	print_tuple(t2);
	print_tuple(subtract_tuples(t1, t2));
	
	printf("\n");
	t1 = vector(3, 2, 1);
	t2 = vector(5, 6, 7);
	print_tuple(t1);
	print_tuple(t2);
	print_tuple(subtract_tuples(t1, t2));

	printf("\n");
	t1 = tuple(1, -2, 3, -4);
	print_tuple(t1);
	print_tuple(negate_tuple(t1));
}

static void	multiply_test(char *title) {
	printf("----------%s----------\n", title);
	t_tuple	t1;

	t1 = tuple(1, -2, 3, -4);
	print_tuple(t1);
	print_tuple(multiply_tuple(t1, 3.5));
	
	printf("\n");
	t1 = tuple(1, -2, 3, -4);
	print_tuple(t1);
	print_tuple(multiply_tuple(t1, 0.5));
}

static void	divide_test(char *title) {
	printf("----------%s----------\n", title);
	t_tuple	t1;

	t1 = tuple(1, -2, 3, -4);
	print_tuple(t1);
	print_tuple(divide_tuple(t1, 2));
}

static void magnitude_test(char *title) {
	printf("----------%s----------\n", title);
	t_tuple	t1;

	t1 = vector(1, 0, 0);
	print_tuple(t1);
	printf("Magnitude => %2.f\n", magnitude(t1));
	t1 = vector(0, 1, 0);
	print_tuple(t1);
	printf("Magnitude => %2.f\n", magnitude(t1));
	t1 = vector(0, 0, 1);
	print_tuple(t1);
	printf("Magnitude => %2.f\n", magnitude(t1));
	t1 = vector(1, 2, 3);
	print_tuple(t1);
	printf("Magnitude => %2.f\n", magnitude(t1));
	t1 = vector(-1, -2, -3);
	print_tuple(t1);
	printf("Magnitude => %2.f\n", magnitude(t1));
}

static void normalize_test(char *title) {
	printf("----------%s----------\n", title);
	t_tuple	t1;

	t1 = vector(4, 0, 0);
	print_tuple(t1);
	print_tuple(normalize(t1));
	printf("\n");
	t1 = vector(1, 2, 3);
	print_tuple(t1);
	print_tuple(normalize(t1));
}

static void dot_test(char *title) {
	printf("----------%s----------\n", title);
	t_tuple	t1;
	t_tuple	t2;

	t1 = vector(1, 2, 3);
	t2 = vector(2, 3, 4);
	print_tuple(t1);
	print_tuple(t2);
	printf("Dot => %.2f\n", dot(t1, t2));
}

int	main(void) {
	sum_test("Sum");
	subtract_test("Subtract");
	//Check after if is to keep the calc with the W
	multiply_test("Multiply");
	divide_test("Divide");
	magnitude_test("Magnitude");
	normalize_test("Normalize");
	dot_test("Dot");
}
