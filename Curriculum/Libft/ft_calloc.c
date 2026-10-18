#include "libft.h"
#include <strings.h>

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*p;
	size_t			total;

	if (n != 0 && size > SIZE_MAX / n)
		return (NULL);
	total = n * size;
	if (total == 0)
		return (malloc(1));
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
