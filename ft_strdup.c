#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	size;

	size = ft_strlen(s) + 1;
	d = malloc(size);
	if (d == NULL)
		return (NULL);
	memmove(d, s, size);
	return (d);
}
