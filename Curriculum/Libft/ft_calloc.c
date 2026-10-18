#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			total;

	total = n * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (total--)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
