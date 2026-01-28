#include "head.h"

void	print_tuple_simple(const char *name, t_tuple t)
{
	printf(C_LABEL "%s: " C_VEC "(%.5f, %.5f, %.5f, %.1f)\n" C_RESET,
		name, t.x, t.y, t.z, t.w);
}
void	print_matrix_simple(t_matrix m)
{
	int	i;
	int	j;

	printf(C_MAT);
	for (i = 0; i < 4; i++)
	{
		printf("    [ ");
		for (j = 0; j < 4; j++)
			printf("%7.3f ", m.matrix[i][j]);
		printf("]\n");
	}
	printf(C_RESET);
}
void	print_material(t_material m)
{
	printf(C_TITLE "Material\n" C_RESET);
	print_tuple_simple("  color", m.color);
	printf(C_LABEL "  ambient:   " C_VALUE "%.3f\n" C_RESET, m.ambient);
	printf(C_LABEL "  diffuse:   " C_VALUE "%.3f\n" C_RESET, m.difuse);
	printf(C_LABEL "  specular:  " C_VALUE "%.3f\n" C_RESET, m.specular);
	printf(C_LABEL "  shininess: " C_VALUE "%.3f\n" C_RESET, m.shininess);
}
static const char	*object_type_str(enum object_type type)
{
	if (type == SPHERE)
		return ("SPHERE");
	if (type == PLANE)
		return ("PLANE");
	if (type == CYLINDER)
		return ("CYLINDER");
	return ("UNKNOWN");
}
void	print_object(t_object o)
{
	printf(C_TITLE "Object [%s]\n" C_RESET, object_type_str(o.type));

	print_tuple_simple("  position", o.position);

	printf(C_LABEL "  transform:\n" C_RESET);
	print_matrix_simple(o.transform);

	print_material(o.material);

	if (o.diameter > 0)
		printf(C_LABEL "  diameter: " C_VALUE "%.3f\n" C_RESET, o.diameter);
	if (o.height > 0)
		printf(C_LABEL "  height:   " C_VALUE "%.3f\n" C_RESET, o.height);

	printf("\n");
}

void	print_computations(t_computations c)
{
	printf(C_TITLE "Computations\n" C_RESET);

	printf(C_LABEL "  t:        " C_VALUE "%.5f\n" C_RESET, c.t);

	print_tuple_simple("  point", c.point);
	print_tuple_simple("  eyev", c.eyev);
	print_tuple_simple("  normalv", c.normalv);

	printf(C_LABEL "  inside:   " C_VALUE "%s\n" C_RESET,
		c.inside ? "true" : "false");

	if (c.object)
	{
		printf("\n");
		printf(C_LABEL "  └─ object\n" C_RESET);
		print_object(*(c.object));
	}
	else
	{
		printf(C_LABEL "  object:   " C_WARN "NULL\n" C_RESET);
	}

	printf("\n");
}




static int	is_identity_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((i == j && m.matrix[i][j] != 1.0f)
				|| (i != j && m.matrix[i][j] != 0.0f))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	print_camera(t_camera *c)
{
	if (!c)
	{
		printf(C_WARN "Camera: NULL\n" C_RESET);
		return;
	}

	printf(C_TITLE "Camera\n" C_RESET);

	printf(C_LABEL "  resolution: "
		   C_VALUE "%.0fx%.0f\n" C_RESET,
		c->hsize, c->vsize);

	printf(C_LABEL "  fov:        " C_VALUE "%.3f rad\n" C_RESET, c->fov);
	printf(C_LABEL "  pixel_size: " C_VALUE "%.6f\n" C_RESET, c->pixel_size);
	printf(C_LABEL "  half_w:     " C_VALUE "%.6f\n" C_RESET, c->half_w);
	printf(C_LABEL "  half_h:     " C_VALUE "%.6f\n" C_RESET, c->half_h);

	print_tuple_simple("  position", c->position);
	print_tuple_simple("  direction", c->direction);

	if (!is_identity_matrix(c->transform))
	{
		printf(C_LABEL "  transform:\n" C_RESET);
		print_matrix(c->transform);
	}
	else
	{
		printf(C_LABEL "  transform: " C_VALUE "identity\n" C_RESET);
	}
}


static void	print_amblight(t_amblight *a)
{
	if (!a)
	{
		printf(C_WARN "Ambient light: NULL\n" C_RESET);
		return;
	}

	printf(C_TITLE "Ambient Light\n" C_RESET);
	printf(C_LABEL "  ratio: " C_VALUE "%.3f\n" C_RESET, a->ratio);
	print_tuple_simple("  color", a->color);
}


static void	print_material_compact(t_material m)
{
	printf(C_LABEL "      material\n" C_RESET);
	print_tuple_simple("        color", m.color);
	printf(C_LABEL "        amb: " C_VALUE "%.2f  "
		   C_LABEL "dif: " C_VALUE "%.2f  "
		   C_LABEL "spec: " C_VALUE "%.2f  "
		   C_LABEL "shin: " C_VALUE "%.1f\n" C_RESET,
		m.ambient, m.difuse, m.specular, m.shininess);
}


static void	print_object_world(t_object *o, unsigned int index)
{
	if (!o)
		return;

	printf(C_TITLE "  [%u] %s\n" C_RESET, index,
		object_type_str(o->type));

	print_tuple_simple("      position", o->position);
	print_tuple_simple("      normal", o->normal);

	if (o->diameter > 0)
		printf(C_LABEL "      diameter: " C_VALUE "%.3f\n" C_RESET,
			o->diameter);
	if (o->height > 0)
		printf(C_LABEL "      height:   " C_VALUE "%.3f\n" C_RESET,
			o->height);

	print_material_compact(o->material);

	if (!is_identity_matrix(o->transform))
		printf(C_WARN "      transform: (non-identity)\n" C_RESET);
}

void	print_light(t_light l)
{
	printf(C_TITLE "Light\n" C_RESET);
	print_tuple_simple("  position", l.position);
	print_tuple_simple("  intensity", l.intensity);
}

void	print_world(t_world *w)
{
	unsigned int	i;

	printf(C_TITLE "World\n" C_RESET);

	print_light(w->light);

	printf(C_LABEL "\nObjects (%u)\n" C_RESET, w->n_objs);

	if (!w->objects || w->n_objs == 0)
	{
		printf(C_WARN "  (no objects)\n" C_RESET);
		return;
	}

	i = 0;
	while (i < w->n_objs)
	{
		print_object_world(w->objects[i], i);
		i++;
	}

	printf("\n");
}

void	print_scene(t_scene *s)
{
	if (!s)
	{
		printf(C_WARN "Scene: NULL\n" C_RESET);
		return;
	}

	printf(C_TITLE "================ SCENE ================\n" C_RESET);

	print_amblight(s->amblight);

	printf("\n");
	print_camera(s->camera);

	printf("\n");
	if (s->world)
		print_world((s->world));
	else
		printf(C_WARN "World: NULL\n" C_RESET);

	printf(C_TITLE "=======================================\n\n" C_RESET);
}
