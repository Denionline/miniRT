#include "head.h"

void	*saffe_calloc(t_scene *scene, char *s,size_t n, size_t size)
{
	void	*new_alloc;

	new_alloc = ft_calloc(n, size);
	if (!new_alloc)
		end(scene, ERR_MALLOC, s, s != NULL);
	return (new_alloc);
}
