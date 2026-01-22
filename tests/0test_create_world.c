#include "head.h"

// int	main(void) {
// 	t_world			w = default_world();
// 	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
// 	t_intersections	xs = intersect_world(w, r);

// 	printf("xs.count = %d\n", xs.count);
// 	printf("xs[0].t = %.2f\n", xs.array[0].t);
// 	printf("xs[1].t = %.2f\n", xs.array[1].t);
// 	printf("xs[2].t = %.2f\n", xs.array[2].t);
// 	printf("xs[3].t = %.2f\n", xs.array[3].t);
// }

void print_object(t_object obj)
{
    printf("===== Object =====\n");
    printf("Type      : %d\n", obj.type);   // Replace %d with enum-to-string if you have a function
    printf("Position  : \n"); 
    print_tuple(obj.position);           // Your existing function for t_tuple
    printf("Transform :\n");
    print_matrix(obj.transform);         // Your existing function for t_matrix
    printf("Material  :\n");
    // print_material(obj.material);        // Your existing function for t_material
    printf("Diameter  : %.2f\n", obj.diameter);
    printf("Height    : %.2f\n", obj.height);
    printf("==================\n");
}

void print_computations(t_computations comp)
{
    printf("=== Computations ===\n");
    
    printf("Object    :\n");
    if (comp.object)
        print_object(*comp.object);
    else
        printf("NULL\n");
    
    printf("Point     : \n");
    print_tuple(comp.point);
    
    printf("Eye Vector: \n");
    print_tuple(comp.eyev);
    
    printf("Normal Vec: \n");
    print_tuple(comp.normalv);
    
    printf("t         : %.2f\n", comp.t);
    
    printf("====================\n");
}

int	main(void) {
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_object		*shape = sphere();
	t_intersection	i = intersection(4, shape);
	t_computations	comps = prepare_computations(i, r);

	print_computations(comps);
}
