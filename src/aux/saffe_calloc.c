#include "head.h"

void	*saffe_calloc(size_t n, size_t size)
{
	void	*new_alloc;

	new_alloc = ft_calloc(n, size);
	if (!new_alloc)
		exit(42);
	return (new_alloc);
}
